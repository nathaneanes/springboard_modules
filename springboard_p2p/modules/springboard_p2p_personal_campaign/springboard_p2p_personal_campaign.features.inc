<?php
/**
 * @file
 * springboard_p2p_personal_campaign.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function springboard_p2p_personal_campaign_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function springboard_p2p_personal_campaign_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function springboard_p2p_personal_campaign_node_info() {
  $items = array(
    'p2p_personal_campaign' => array(
      'name' => t('Peer to peer personal campaign'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Campaign Name'),
      'help' => '',
    ),
  );
  return $items;
}