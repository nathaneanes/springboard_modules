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


  /**
   * @param DateTime $date
   */
  public function __construct(DateTime $date) {
    $this->date = $date;
    $this->today = new DateTime();

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
    return $this->scheduledFirstTimeCharges + $this->scheduledRetriesCharges;
  }

  /**
   * @return int
   */
  public function getScheduledValue() {
    return $this->scheduledFirstTimeValue + $this->scheduledRetiresValue;
  }

  /**
   * @todo Is processed value for the day the same as total value for the day?
   *
   * @return int
   */
  public function getTotalValue() {
    return $this->processedValue;
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
    return $this->processedCharges;
  }

  /**
   * @return int
   */
  public function getProcessedValue() {
    return $this->processedValue;
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
    return $this->today == $this->date;
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
