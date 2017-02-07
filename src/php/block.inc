<?php
/**
 * @file
 *  CellularUI block functions.
 */

/**
 * Attach library & settings for cached blocks.
 * @param type $delta
 * @return array
 */
function cellular_mod_block_view($delta = '') {
  if ($delta == 'cellular_mod_delta') {
    drupal_add_library('cellular_mod', 'cellular_mod');
    drupal_add_js(drupal_get_path('module', 'cellular_mod') . 'inc/cellular_mod.settings.js');

    $block = array (
    //'subject' => t('My block title'),
    //'content' => '<p>' . t('This is some text that will go in the block.') . '</p>',
    );
    dpm($delta);

    return $block;
  }
}
