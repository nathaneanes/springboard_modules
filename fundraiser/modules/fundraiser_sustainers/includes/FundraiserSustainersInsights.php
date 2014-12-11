<?php

class FundraiserSustainersInsights {

  public function __construct() {

  }

  public function takeSnapshot(DateTime $time) {
    $snapshot = new FundraiserSustainersDailySnapshot($time);
    $snapshot->save();
  }

  public function getTodaysSnapshot() {
    return new FundraiserSustainersDailySnapshot(new DateTime());
  }

  public function getSnapshot(DateTime $time) {
    return new FundraiserSustainersDailySnapshot($time);
  }

  public function getHistoricalReportPreset($string) {
    $end = new DateTime();

    try {
      $begin = new DateTime($string);
    }
    catch (Exception $e) {
      // Default to past 7 days if we can't figure out what the string is.
      $begin = new DateTime('-7 days');
    }

    // Now go through the normal validation.
    return $this->getHistoricalReport($begin, $end);
  }

  public function getHistoricalReport(DateTime $begin, DateTime $end) {
    // @todo Complain if end date is today or start is after end or range is
    // too big.

    return new FundraiserSustainersHistoricalReport($begin, $end);
  }
}
