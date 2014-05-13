<?php
/**
 * @file
 * springboard_p2p_landing.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function springboard_p2p_landing_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_p2p_referenced_campaigns'
  $field_bases['field_p2p_referenced_campaigns'] = array(
    'active' => 1,
    'cardinality' => 4,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_p2p_referenced_campaigns',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'p2p_campaign' => 'p2p_campaign',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_p2p_side_block'
  $field_bases['field_p2p_side_block'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_p2p_side_block',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'block' => 'block',
        'devel' => 0,
        'menu' => 0,
        'node' => 'node',
        'panels_mini' => 0,
        'shorten' => 0,
        'springboard' => 0,
        'system' => 'system',
        'user' => 0,
        'views' => 0,
        'webform' => 0,
      ),
      'referenceable_operator' => 'AND',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'footer' => 0,
        'header' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_p2p_slide_show'
  $field_bases['field_p2p_slide_show'] = array(
    'active' => 1,
    'cardinality' => 4,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_p2p_slide_show',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'p2p_campaign' => 'p2p_campaign',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}