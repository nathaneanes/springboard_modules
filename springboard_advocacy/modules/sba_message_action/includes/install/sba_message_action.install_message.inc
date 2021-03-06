<?php
function _sba_message_action_install_message_entity() {
  entity_save('sba_message',
    entity_create('sba_message_type',
      array(
        'label' => 'SBA Message Action Message',
        'type' => 'sba_message_action_message'
      )
    )
  );

  $field_bases = array();

// Exported field_base: 'field_sba_bottom_conclusion'
  $field_bases['field_sba_bottom_conclusion'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sba_bottom_conclusion',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

// Exported field_base: 'field_sba_editable_area'
  $field_bases['field_sba_editable_area'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sba_editable_area',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

// Exported field_base: 'field_sba_editable_area_optional'
  $field_bases['field_sba_editable_area_optional'] = array(
    'active' => 1,
    'cardinality' => 2,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sba_editable_area_optional',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'required' => 'Editing is required',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

// Exported field_base: 'field_sba_action_id'
  $field_bases['field_sba_action_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sba_action_id',
    'foreign keys' => array(),
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
          'sba_message_action' => 'sba_message_action',
          'sba_social_action' => 'sba_social_action',

        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

// Exported field_base: 'field_sba_greeting'
  $field_bases['field_sba_greeting'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sba_greeting',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

// Exported field_base: 'field_sba_message'
  $field_bases['field_sba_message'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sba_message',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

// Exported field_base: 'field_sba_placeholder_greeting'
  $field_bases['field_sba_placeholder_greeting'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sba_placeholder_greeting',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

// Exported field_base: 'field_sba_signature'
  $field_bases['field_sba_signature'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sba_signature',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

// Exported field_base: 'field_sba_subject'
  $field_bases['field_sba_subject'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sba_subject',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

// Exported field_base: 'field_sba_subject_editable'
  $field_bases['field_sba_subject_editable'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sba_subject_editable',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Not editable' => 'Not editable',
        'Editable' => 'Editable',
        'Editing is required' => 'Editing is required',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

// Exported field_base: 'field_sba_user_editable'
  $field_bases['field_sba_user_editable'] = array(
    'active' => 1,
    'cardinality' => 2,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_sba_user_editable',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'editable' => 'I want the user to be able to edit this message',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  foreach ($field_bases as $key => $values) {
    $base = field_info_field($key);
    if (empty($base)) {
      field_create_field($values);
    }
  }

  $field_instances = array();

// Exported field_instance: 'sba_message-sba_message_action_message-field_sba_bottom_conclusion'
  $field_instances['sba_message-sba_message_action_message-field_sba_bottom_conclusion'] = array(
    'bundle' => 'sba_message_action_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use this field to add a non-editable area to the bottom of your message.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'sba_message',
    'field_name' => 'field_sba_bottom_conclusion',
    'label' => 'Conclusion',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
  );

// Exported field_instance: 'sba_message-sba_message_action_message-field_sba_editable_area'
  $field_instances['sba_message-sba_message_action_message-field_sba_editable_area'] = array(
    'bundle' => 'sba_message_action_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'sba_message',
    'field_name' => 'field_sba_editable_area',
    'label' => 'Default text that the user may alter:',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 9,
    ),
  );

// Exported field_instance: 'sba_message-sba_message_action_message-field_sba_editable_area_optional'
  $field_instances['sba_message-sba_message_action_message-field_sba_editable_area_optional'] = array(
    'bundle' => 'sba_message_action_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'sba_message',
    'field_name' => 'field_sba_editable_area_optional',
    'label' => 'Editing is required?',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 8,
    ),
  );

// Exported field_instance: 'sba_message-sba_message_action_message-field_sba_action_id'
  $field_instances['sba_message-sba_message_action_message-field_sba_action_id'] = array(
    'bundle' => 'sba_message_action_message',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'sba_message',
    'field_name' => 'field_sba_action_id',
    'label' => 'Action ID',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'action' => 'hide',
          'action_on_edit' => 1,
          'fallback' => 'form_error',
          'providers' => array(
            'node_url' => 1,
            'og_context' => FALSE,
            'url' => 0,
          ),
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
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
      'weight' => 4,
    ),
  );

// Exported field_instance: 'sba_message-sba_message_action_message-field_sba_greeting'
  $field_instances['sba_message-sba_message_action_message-field_sba_greeting'] = array(
    'bundle' => 'sba_message_action_message',
    'default_value' => array(
      0 => array(
        'value' => 'Dear [target:salutation] [target:last_name]',
      ),
    ),
    'deleted' => 0,
    'description' => 'Available tokens: [target:salutation] [target:first_name] [target:last_name]',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'sba_message',
    'field_name' => 'field_sba_greeting',
    'label' => 'Greeting (for message to be delivered)',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

// Exported field_instance: 'sba_message-sba_message_action_message-field_sba_message'
  $field_instances['sba_message-sba_message_action_message-field_sba_message'] = array(
    'bundle' => 'sba_message_action_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'sba_message',
    'field_name' => 'field_sba_message',
    'label' => 'Message/Intro',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 15,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
  );

// Exported field_instance: 'sba_message-sba_message_action_message-field_sba_placeholder_greeting'
  $field_instances['sba_message-sba_message_action_message-field_sba_placeholder_greeting'] = array(
    'bundle' => 'sba_message_action_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'sba_message',
    'field_name' => 'field_sba_placeholder_greeting',
    'label' => 'Placeholder Greeting (for display on the action)',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

// Exported field_instance: 'sba_message-sba_message_action_message-field_sba_signature'
  $field_instances['sba_message-sba_message_action_message-field_sba_signature'] = array(
    'bundle' => 'sba_message_action_message',
    'default_value' => array(
      0 => array(
        'value' => "Sincerely, \n\n[contact:first_name] [contact:last_name]",
      ),
    ),
    'deleted' => 0,
    'description' => 'Available tokens: [contact:first_name] [contact:last_name] [contact:address]',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'sba_message',
    'field_name' => 'field_sba_signature',
    'label' => 'Signature',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

// Exported field_instance: 'sba_message-sba_message_action_message-field_sba_subject'
  $field_instances['sba_message-sba_message_action_message-field_sba_subject'] = array(
    'bundle' => 'sba_message_action_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'sba_message',
    'field_name' => 'field_sba_subject',
    'label' => 'Subject text',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

// Exported field_instance: 'sba_message-sba_message_action_message-field_sba_subject_editable'
  $field_instances['sba_message-sba_message_action_message-field_sba_subject_editable'] = array(
    'bundle' => 'sba_message_action_message',
    'default_value' => array(
      0 => array(
        'value' => 'Not editable',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'sba_message',
    'field_name' => 'field_sba_subject_editable',
    'label' => 'Subject editable by advocate? (for single message actions only)',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

// Exported field_instance: 'sba_message-sba_message_action_message-field_sba_user_editable'
  $field_instances['sba_message-sba_message_action_message-field_sba_user_editable'] = array(
    'bundle' => 'sba_message_action_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'sba_message',
    'field_name' => 'field_sba_user_editable',
    'label' => 'User editable',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

// Translatables
// Included for use with string extractors like potx.
  t('Action ID');
  t('Conclusion');
  t('Default text that the user may alter:');
  t('Editing is required?');
  t('Greeting (for message to be delivered)');
  t('Message');
  t('Placeholder Greeting (for display on the action)');
  t('Signature');
  t('Subject editable by advocate? (for single message actions only)');
  t('Subject text');
  t('User editable');

  foreach ($field_instances as $instance) {
    field_create_instance($instance);
  }

  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sba_editable|sba_message|sba_message_action_message|form';
  $field_group->group_name = 'group_sba_editable';
  $field_group->entity_type = 'sba_message';
  $field_group->bundle = 'sba_message_action_message';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sba_message_body';
  $field_group->label = 'Editable Area';
  $field_group->weight = '13';
  $field_group->children = array(
    0 => 'field_sba_editable_area',
    1 => 'field_sba_editable_area_optional',
  );
  $field_group->format_type = 'fieldset';
  $field_group->format_settings = array(
    'label' => 'Editable Area',
    'instance_settings' => array(
      'required_fields' => 1,
      'classes' => 'group-sba-editable field-group-fieldset',
      'description' => 'For single message actions only: use this field to create an area of your message that will be editable by advocates. Actions with multiple messages cannot be edited by advocates.',
    ),
    'formatter' => 'open',
  );

  $export['group_sba_editable|sba_message|sba_message_action_message|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sba_greeting|sba_message|sba_message_action_message|form';
  $field_group->group_name = 'group_sba_greeting';
  $field_group->entity_type = 'sba_message';
  $field_group->bundle = 'sba_message_action_message';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->label = 'Greeting';
  $field_group->weight = '1';
  $field_group->children = array(
    0 => 'field_sba_greeting',
    1 => 'field_sba_placeholder_greeting',
  );
  $field_group->format_type = 'fieldset';
  $field_group->format_settings = array(
    'label' => 'Greeting',
    'instance_settings' => array(
      'required_fields' => 1,
      'classes' => 'group-sba-greeting field-group-fieldset',
      'description' => '',
    ),
    'formatter' => 'open',
  );
  $export['group_sba_greeting|sba_message|sba_message_action_message|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sba_message_body|sba_message|sba_message_action_message|form';
  $field_group->group_name = 'group_sba_message_body';
  $field_group->entity_type = 'sba_message';
  $field_group->bundle = 'sba_message_action_message';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->label = 'Message Body';
  $field_group->weight = '2';
  $field_group->children = array(
    0 => 'field_sba_bottom_conclusion',
    1 => 'field_sba_message',
    2 => 'field_sba_user_editable',
    3 => 'group_sba_editable',
  );
  $field_group->format_type = 'fieldset';
  $field_group->format_settings = array(
    'label' => 'Message Body',
    'instance_settings' => array(
      'required_fields' => 1,
      'classes' => 'group-sba-message-body field-group-fieldset',
      'description' => 'Enter the message to be sent. If you don\'t want advocates to edit the message, use only this field.',
    ),
    'formatter' => 'open',
  );
  $export['group_sba_message_body|sba_message|sba_message_action_message|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sba_subject|sba_message|sba_message_action_message|form';
  $field_group->group_name = 'group_sba_subject';
  $field_group->entity_type = 'sba_message';
  $field_group->bundle = 'sba_message_action_message';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->label = 'Subject';
  $field_group->weight = '0';
  $field_group->children = array(
    0 => 'field_sba_subject',
    1 => 'field_sba_subject_editable',
  );
  $field_group->format_type = 'fieldset';
  $field_group->format_settings = array(
    'label' => 'Subject',
    'instance_settings' => array(
      'required_fields' => 1,
      'classes' => 'group-sba-subject field-group-fieldset',
      'description' => '',
    ),
    'formatter' => 'open',
  );
  $export['group_sba_subject|sba_message|sba_message_action_message|form'] = $field_group;
  foreach ($export as $field_group) {
    field_group_group_save($field_group);
  }

  $sba_message_types = variable_get('sba_message_node_types', array(''));
  $sba_message_types = array_merge($sba_message_types, array('sba_message_action' => 'sba_message_action_message'));
  variable_set('sba_message_node_types', $sba_message_types);
}

/**
 * Delete springboard message fields
 */
function _sba_message_action_delete_message_entity_fields() {
  $fields = array(
    'field_sba_signature',
    'field_sba_placeholder_greeting',
    'field_sba_greeting',
    'field_sba_message',
    'field_sba_subject',
    'field_sba_user_editable',
    'field_sba_subject_editable',
    'field_sba_editable_area_optional',
    'field_sba_editable_area',
    'field_sba_bottom_conclusion'
  );

  foreach ($fields as $field_name) {
    $field = field_info_instance('node', $field_name, 'sba_message_action');
    field_delete_instance($field);
  }

  drupal_set_message('Sba Message fields deleted.');
  field_group_field_attach_delete_bundle('sba_message','sba_message_action_message');
  $twit = sba_message_type_load('sba_message_action_message');
  if($twit) {
    sba_message_type_delete($twit);
  }
}
