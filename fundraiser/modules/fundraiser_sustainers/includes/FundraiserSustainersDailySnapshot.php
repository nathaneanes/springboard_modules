<?php

/**
 * Class FundraiserSustainersDailySnapshot
 */
class FundraiserSustainersDailySnapshot {

  /**
   * @var DateTime
   * Today.
   */
  protected $today;

  /**
   * @var DateTime
   * The day of this Snapshot.
   */
  protected $date;

  /**
   * @var int
   * The timestamp of the day start. Used for database queries.
   */
  protected $beginTimestamp;

  /**
   * @var int
   * The timestamp of the day start of the following day. Used for database
   * queries.
   */
  protected $endTimestamp;

  /**
   * @var int
   * Timestamp when this was last saved.
   */
  protected $lastUpdated;

  /**
   * @var int
   * Number of first time charges scheduled.
   */
  protected $scheduledFirstTimeCharges;

  /**
   * @var int
   * Number of retry charges scheduled.
   */
  protected $scheduledRetriesCharges;

  /**
   * @var int
   * Value (in cents) of first time charges scheduled.
   */
  protected $scheduledFirstTimeValue;

  /**
   * @var int
   * Value (in cents) of retry charges scheduled.
   */
  protected $scheduledRetiresValue;

  /**
   * @var int
   */
  protected $retriedCharges;

  /**
   * @var int
   */
  protected $retriedValue;

  /**
   * @var int
   */
  protected $processedCharges;

  /**
   * @var int
   */
  protected $processedValue;

  /**
   * @var int
   */
  protected $rescheduledCharges;

  /**
   * @var int
   */
  protected $rescheduledValue;

  /**
   * @var int
   */
  protected $abandonedCharges;

  /**
   * @var int
   */
  protected $abandonedValue;

  /**
   * @var int
   * Number of successful charges completed so far in this day.
   */
  protected $successes;

  /**
   * @var int
   * Number of failed charges attempted so far in this day.
   */
  protected $failures;

  protected $successValue;

  protected $failureValue;

  /**
   * @param DateTime $date
   */
  public function __construct(DateTime $date) {
    $this->date = $date;
    $this->date->setTime(0, 0, 0);

    $this->beginTimestamp = $this->date->getTimestamp();

    $date_end = clone $this->date;
    $date_end->add(new DateInterval('P1D'));
    $date_end->setTime(0, 0, 0);
    $this->endTimestamp = $date_end->getTimestamp();

    $this->today = new DateTime();
    $this->today->setTime(0, 0, 0);

    $this->load();
  }

  /**
   *
   */
  public function save() {
    $this->lastUpdated = REQUEST_TIME;

    // Save to the database.
    $this->saveRow();
  }

  /**
   * @return DateTime
   */
  public function getDate() {
    return $this->date;
  }

  /**
   * @return int
   */
  public function getScheduledCharges() {
    return $this->scheduledFirstTimeCharges + $this->scheduledRetriesCharges + $this->getProcessedCharges();
  }

  /**
   * @return int
   */
  public function getScheduledValue() {
    return $this->scheduledFirstTimeValue + $this->scheduledRetiresValue + $this->getProcessedValue();
  }

  /**
   *
   * @return int
   */
  public function getTotalValue() {
    return $this->getScheduledValue();
  }

  /**
   * @return int
   */
  public function getSuccesses() {
    return $this->successes;
  }

  /**
   * @return int
   */
  public function getFailures() {
    return $this->failures;
  }

  /**
   * @return int
   */
  public function getAbandonedCharges() {
    return $this->abandonedCharges;
  }

  /**
   * @return int
   */
  public function getAbandonedValue() {
    return $this->abandonedValue;
  }

  /**
   * @return int
   */
  public function getProcessedCharges() {
    return $this->getSuccesses() + $this->getFailures();
  }

  /**
   * @return int
   */
  public function getProcessedValue() {
    return $this->getSuccessValue() + $this->getFailureValue();
  }

  public function getSuccessValue() {
    return $this->successValue;
  }

  public function getFailureValue() {
    return $this->failureValue;
  }

  /**
   * @return int
   */
  public function getRescheduledCharges() {
    return $this->rescheduledCharges;
  }

  /**
   * @return int
   */
  public function getRescheduledValue() {
    return $this->rescheduledValue;
  }

  /**
   * @return int
   */
  public function getRetriedCharges() {
    return $this->retriedCharges;
  }

  /**
   * @return int
   */
  public function getRetriedValue() {
    return $this->retriedValue;
  }

  /**
   * @return int
   */
  public function getScheduledFirstTimeCharges() {
    return $this->scheduledFirstTimeCharges;
  }

  /**
   * @return int
   */
  public function getScheduledFirstTimeValue() {
    return $this->scheduledFirstTimeValue;
  }

  /**
   * @return int
   */
  public function getScheduledRetiresValue() {
    return $this->scheduledRetiresValue;
  }

  /**
   * @return int
   */
  public function getScheduledRetriesCharges() {
    return $this->scheduledRetriesCharges;
  }

  /**
   * @return bool
   */
  protected function shouldUseLiveData() {
    return $this->today->format('Y-m-d') == $this->date->format('Y-m-d');
  }

  /**
   *
   */
  protected function load() {
    $this->initializeValues();
    if ($this->shouldUseLiveData()) {
      // Calculate new stuff since it's today.
      $this->calculateValues();
    }
    else {
      // Look for a record in the DB and load it.
      // If there's no existing record, calculate new values.
      $row = $this->findRow();
      if (empty($row)) {
        $this->calculateValues();
      }
      else {
        foreach ($row as $key => $value) {
          $this->$key = $value;
        }
      }
    }
  }

  /**
   *
   */
  protected function saveRow() {
    // Set up a record array for drupal_write_record or db_insert.
  }

  /**
   * @return array
   */
  protected function findRow() {
    // Query for rows by the Y-m-d date string.
    return array();
  }

  /**
   *
   */
  protected function calculateValues() {
    // Do the DB queries and math stuff here.

    $query = "SELECT did FROM {fundraiser_sustainers} WHERE gateway_resp IS NULL AND attempts = 0 AND next_charge >= :begin AND next_charge < :end";
    $replacements = array(
      ':begin' => $this->beginTimestamp,
      ':end' => $this->endTimestamp,
    );
    $result = db_query($query, $replacements);

    $count = 0;
    $total = 0;
    foreach ($result as $row) {
      $count++;
      $total += $this->getValueFromOrder($row->did);
    }

    $this->scheduledFirstTimeCharges = $count;
    $this->scheduledFirstTimeValue = $total;

    $query = "SELECT did FROM {fundraiser_sustainers} WHERE gateway_resp = 'retry' AND attempts > 0 AND next_charge >= :begin AND next_charge < :end";
    $replacements = array(
      ':begin' => $this->beginTimestamp,
      ':end' => $this->endTimestamp,
    );

    $result = db_query($query, $replacements);

    $count = 0;
    $total = 0;
    foreach ($result as $row) {
      $count++;
      $total += $this->getValueFromOrder($row->did);
    }

    $this->scheduledRetriesCharges = $count;
    $this->scheduledRetiresValue = $total;

    $this->calculateSuccessesAndFailures();
  }

  protected function getValueFromOrder($did) {
    $order = commerce_order_load($did);
    $wrapper = entity_metadata_wrapper('commerce_order', $order);
//      $currency_code = $wrapper->commerce_order_total->currency_code->value();

    return $wrapper->commerce_order_total->amount->value();
  }

  protected function calculateSuccessesAndFailures() {
    $successes = 0;
    $failures = 0;
    $replacements = array(
      ':begin' => $this->beginTimestamp,
      ':end' => $this->endTimestamp,
    );
    $results = db_query("SELECT revision_id, master_did, did, revision_timestamp, attempts, gateway_resp FROM {fundraiser_sustainers_revision} WHERE revision_timestamp >= :begin AND next_charge < :end AND gateway_resp IN ('success', 'failed')", $replacements);

    $processed_dids = array();
    $successValue = 0;
    $failureValue = 0;

    foreach ($results as $new) {
      $replacements = array(
        ':did' => $new->did,
        ':revision_id' => $new->revision_id,
        ':attempts' => $new->attempts,
      );
      $old = db_query("SELECT revision_id, master_did, did, revision_timestamp, attempts, gateway_resp FROM {fundraiser_sustainers_revision} WHERE did = :did AND revision_id < :revision_id AND attempts < :attempts ORDER BY revision_id DESC LIMIT 0,1", $replacements)->fetchObject();

      if (is_object($old) && !in_array($old->did, $processed_dids)) {
        debug($this->getDate()->format('Y-m-d'));
        debug($old);
        debug($new);

        if ((is_null($old->gateway_resp) || $old->gateway_resp != 'success') && $new->gateway_resp == 'success') {
          $successes++;
          $processed_dids[] = $old->did;
          $successValue += $this->getValueFromOrder($old->did);
        }
        elseif ((is_null($old->gateway_resp) || $old->gateway_resp != 'failed') && $new->gateway_resp == 'failed') {
          $failures++;
          $processed_dids[] = $old->did;
          $failureValue += $this->getValueFromOrder($old->did);
        }
      }
    }

    $this->successes = $successes;
    $this->failures = $failures;
    $this->successValue = $successValue;
    $this->failureValue = $failureValue;
  }

  /**
   *
   */
  protected function initializeValues() {
    $this->scheduledFirstTimeCharges = 0;
    $this->scheduledRetriesCharges = 0;
    $this->scheduledFirstTimeValue = 0;
    $this->scheduledRetiresValue = 0;
    $this->successes = 0;
    $this->failures = 0;

    $this->abandonedCharges = 0;
    $this->abandonedValue = 0;
    $this->rescheduledCharges = 0;
    $this->rescheduledValue = 0;
    $this->processedCharges = 0;
    $this->processedValue = 0;
    $this->retriedCharges = 0;
    $this->retriedValue = 0;
  }
}
