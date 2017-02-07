<?php
/**
 * @file
 * cellular_mod_settings.inc
 */

/**
 * Cellular UI settings.
 */
function cellular_mod_settings_form() {

}

/**
 * Instance form validation handler.
 */
function cellular_mod_settings_form_validate($form, $form_state) {
  if (strlen($form_state['values']['name']) >= 65) {
    form_set_error('name', t('The name entered is too long =(.'));
  }
}
