(function ($) {
  Drupal.behaviors.fundraiserTickets = {
    attach: function(context, settings) {

      if (Drupal.settings.fundraiserTickets) {
        new Drupal.fundraiserTickets();
      }
    }
  };

  /**
   * Set the amounts on page load
   */
  Drupal.fundraiserTickets = function() {
    this.ticketPrices = Drupal.settings.fundraiserTickets.ticketPrices;
    this.setAmounts();
    this.ticketSelect();
  }

  /**
   * Set the amounts on select
   */
  // Iterate over each field in the settings and add listener
  Drupal.fundraiserTickets.prototype.ticketSelect = function() {
    var self = this;
    $.each(self.ticketPrices, function(productId, price) {
      $('#product-' + productId + '-ticket-quant').change(function() {
        self.setAmounts();
      });
    });

    $('#fundraiser-tickets-extra-donation').keyup(function() {
      self.setAmounts();
    });

  }

  /**
   * Update the various HTML elements with our amounts
   */
  Drupal.fundraiserTickets.prototype.setAmounts = function() {
    var self = this,
    total = self.calcTotal(),
    extra = self.calcExtra(),
    totalQuantity = self.calcQuantity();
    // @todo Change this to support multiple currencies.
    // See if Commerce provides something like commerce_currency_format in JS.
    $('#fundraiser-tickets-total-cost').text('$ ' + (total).formatMoney(2, '.', ','));
    // @todo Use the donation form's currency formatting instead.
    $('#fundraiser-tickets-extra-donation-display').text('$ ' + (extra).formatMoney(2, '.', ','));
    $("input[name='submitted[amount]']").val((total).formatMoney(2, '.', ''));
    $('#fundraiser-tickets-total-quant').text(totalQuantity);
    $.each(self.ticketPrices, function(productId, price) {
      // @todo Adjust the currency formatting.
      $('#product-' + productId + '-tickets-total').text('$ ' + (self.calcField(productId, price)).formatMoney(2, '.', ','));
    });
  }

  /**
   * Calculate the value of a field
   */
  Drupal.fundraiserTickets.prototype.calcField = function(productId, price) {
    return $('#product-' + productId + '-ticket-quant').val() * price;
  }

  /**
   * Calculate the total amount
   */
  Drupal.fundraiserTickets.prototype.calcTotal = function() {
    var self = this;
    var total = 0;
    $.each(self.ticketPrices, function(productId, price) {
      total = total + (price * $('#product-' + productId + '-ticket-quant').val());
    });
    if ($('#fundraiser-tickets-extra-donation').val()){
      total = total + parseFloat($('#fundraiser-tickets-extra-donation').val());
    }
    return total;
  }

  /**
   * Calculate the extra amount
   */
  Drupal.fundraiserTickets.prototype.calcExtra = function() {
    var self = this;
    var extra = 0;
    if ($('#fundraiser-tickets-extra-donation').val()){
      extra = parseFloat($('#fundraiser-tickets-extra-donation').val());
    }
    return extra;
  }


  /**
   * Calculate the quantity of tickets selected
   */
  Drupal.fundraiserTickets.prototype.calcQuantity = function() {
    var self = this;
    var quantity = 0;
    $.each(self.ticketPrices, function(productId, price) {
       quantity = quantity + Number($('#product-' + productId + '-ticket-quant').val());
    });
    return quantity;
  }

  /**
   * Format values as money
   *
   * http://stackoverflow.com/a/149099/1060438
   */
  Number.prototype.formatMoney = function(c, d, t) {
    var n = this, c = isNaN(c = Math.abs(c)) ? 2 : c, d = d == undefined ? "," : d, t = t == undefined ? "." : t, s = n < 0 ? "-" : "", i = parseInt(n = Math.abs(+n || 0).toFixed(c)) + "", j = (j = i.length) > 3 ? j % 3 : 0;
    return s + (j ? i.substr(0, j) + t : "") + i.substr(j).replace(/(\d{3})(?=\d)/g, "$1" + t) + (c ? d + Math.abs(n - i).toFixed(c).slice(2) : "");
  };

})(jQuery);
