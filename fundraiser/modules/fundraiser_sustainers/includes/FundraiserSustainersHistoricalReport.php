<?php

class FundraiserSustainersHistoricalReport {

  /**
   * @var DateTime
   */
  protected $begin;

  /**
   * @var DateTime
   */
  protected $end;

  /**
   * @var array<FundraiserSustainersDailySnapshot>
   */
  protected $snapshots;

  /**
   * @var DateTime
   */
  protected $currentKey;

  /**
   *
   * @param DateTime $begin
   * @param DateTime $end
   */
  public function __construct(DateTime $begin, DateTime $end) {
    $this->begin = $begin;
    $this->end = $end;

    $this->loadSnapshots();
  }

  public function loadSnapshots() {
    $interval = DateInterval::createFromDateString('1 day');
    $period = new DatePeriod($this->begin, $interval, $this->end);

    foreach ($period as $date) {
      $this->snapshots[$date->format("Y-m-d")] = new FundraiserSustainersDailySnapshot($date);
    }

  }

  /**
   * @return array<FundraiserSustainersDailySnapshot>
   */
  public function getSnapshots() {
    return $this->snapshots;
  }

}
