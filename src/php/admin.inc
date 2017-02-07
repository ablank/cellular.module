<?php
/**
 * Implements hook_menu().
 */
function cellular_mod_menu() {
  $items['admin/config/user-interface/cellular_mod'] = array(
    'title' => 'Cellular UI',
    'description' => 'Cellular UI instance settings list.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('cellular_mod_settings_form'),
    'access arguments' => array('administer cellular_mod settings'),
    'type' => MENU_NORMAL_ITEM,
    'file' => 'inc/cellular_mod_admin.inc',
  );
  $items['admin/config/user-interface/cellular_mod/%'] = array(
    'title' => 'Cellular UI Instance Settings',
    'description' => 'List instance settings.',
    'page callback' => 'cellular_mod_instance_settings_form',
    'page arguments' => array(4),
    'access arguments' => array('administer cellular_mod settings'),
    'type' => MENU_NORMAL_ITEM,
    'file' => 'inc/cellular_mod_admin.inc',
  );
  $items['admin/config/user-interface/cellular_mod/import'] = array(
    'title' => 'Import Settings',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('cellular_mod_variable_settings_import_form'),
    'access arguments' => array('administer cellular_mod settings'),
    'type' => MENU_NORMAL_ITEM,
    'file' => 'inc/cellular_mod_admin.inc',
  );
  $items['admin/config/user-interface/cellular_mod/%/export'] = array(
    'title' => 'Export Settings',
    'page callback' => 'cellular_mod_export_instance_settings',
    'page arguments' => array(4),
    'access arguments' => array('administer cellular_mod settings'),
    'type' => MENU_CALLBACK,
    'file' => 'inc/cellular_mod_admin.inc',
  );
  $items['admin/config/user-interface/cellular_mod/%/delete/%'] = array(
    'title' => 'Delete Settings',
    'page callback' => 'cellular_mod_delete_instance_settings',
    'page arguments' => array(4, 6),
    'access arguments' => array('administer cellular_mod settings'),
    'type' => MENU_CALLBACK,
    'file' => 'inc/cellular_mod_admin.inc',
  );

  return $items;
}

/**
 * Implements hook_permission().
 */
function cellular_mod_permission() {
  return array(
    'administer cellular_mod settings' => array(
      'title' => t('Administer Cellular UI settings'),
    ),
  );
}

/**
 * Implements hook_variable_settings_form_alter().
 */
function cellular_mod_variable_settings_form_alter(&$form, $form_state, $form_id) {
  if (isset($form_state['build_info']['args'][0]) && $form_state['build_info']['args'][0] == 'cellular_mod') {
    $instance = $form_state['build_info']['args'][1];

    $check = _cellular_mod_return_instances($instance);
    if ($check) {
      // Include additional submit handler to update settings cache.
      $form['#submit'][] = 'cellular_mod_variable_settings_submit';

      // This needs a graceful solution... =/
      $settings = cellular_mod_build_instance_settings($instance, $form['#variable_edit_form']);
      foreach ($form as $key => $component) {
        if (strpos($key, '[instance_id]') !== FALSE) {
          $form[$key] = $settings[$key];
        }
      }
    }
    else {
      hide($form);

      // Alert user; no group was found.
      drupal_set_message(t('No settings group found with the name @name.', array('@name' => $instance)), 'warning');
    }
  }
}

/**
 * Format variable settings form to only display our
 * instance variables.
 */
function cellular_mod_build_instance_settings($instance, $settings) {
  module_load_include('form.inc', 'variable');

  foreach ($settings as $key => $setting) {
    $variable = variable_get_child($setting, $instance);
    $form[$setting][$variable['name']] = variable_form_element($variable);

    if ($setting == 'cellular_mod_navigation_text_[instance_id]') {
      $form[$setting][$variable['name']][0]['#title'] = t('Previous');
      $form[$setting][$variable['name']][1]['#title'] = t('Next');
    }
  }

  return $form;
}
