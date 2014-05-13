<?php
/**
 * @file
 * springboard_p2p_landing.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function springboard_p2p_landing_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-p2p_campaign_landing-field_p2p_referenced_campaigns'
  $field_instances['node-p2p_campaign_landing-field_p2p_referenced_campaigns'] = array(
    'bundle' => 'p2p_campaign_landing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Choose nodes to reference from Peer to peer campaigns. (Typing bring up suggestions.)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_p2p_referenced_campaigns',
    'label' => 'Start your own campaign',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'node-p2p_campaign_landing-field_p2p_side_block'
  $field_instances['node-p2p_campaign_landing-field_p2p_side_block'] = array(
    'bundle' => 'p2p_campaign_landing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Choose a block to reference. (Typing bring up suggestions.)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'blockreference',
        'settings' => array(),
        'type' => 'blockreference_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_p2p_side_block',
    'label' => 'Side Block',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'blockreference',
      'settings' => array(
        'autocomplete_path' => 'blockreference/autocomplete',
        'size' => 60,
      ),
      'type' => 'blockreference_autocomplete',
      'weight' => -2,
    ),
  );

  // Exported field_instance: 'node-p2p_campaign_landing-field_p2p_slide_show'
  $field_instances['node-p2p_campaign_landing-field_p2p_slide_show'] = array(
    'bundle' => 'p2p_campaign_landing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Choose nodes to reference from Peer to peer campaigns for the slideshow. (Typing bring up suggestions.)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_p2p_slide_show',
    'label' => 'Slide Show',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Choose a block to reference. (Typing bring up suggestions.)');
  t('Choose nodes to reference from Peer to peer campaigns for the slideshow. (Typing bring up suggestions.)');
  t('Choose nodes to reference from Peer to peer campaigns. (Typing bring up suggestions.)');
  t('Side Block');
  t('Slide Show');
  t('Start your own campaign');

  return $field_instances;
}