<?php
/**
 * Implements hook_theme().
 */
function cellular_mod_theme() {
  return array(
    'cellular_mod' => array(
      'variables' => array('items' => array(), 'settings' => array()),
      'file' => 'inc/cellular_mod.theme.inc',
    ),
    'cellular_mod_list' => array(
      'variables' => array('items' => array()),
      'file' => 'inc/cellular_mod.theme.inc',
    ),
    'cellular_mod_list_item' => array(
      'variables' => array('item' => array(), 'class' => ''),
      'file' => 'inc/cellular_mod.theme.inc',
    ),
    'cellular_mod_wrapper' => array(
      'variables' => array('output' => array()),
      'file' => 'inc/cellular_mod.theme.inc',
    ),
    'cellular_mod_admin_settings_form' => array(
      'render element' => 'form',
    ),
    'cellular_mod_admin_settings_form_fields' => array(
      'render element' => 'form',
    ),
  );
}
