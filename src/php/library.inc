<?php
/**
 * Implements hook_library().
 */
function cellular_mod_library() {
  $library = libraries_get_path('cellular_mod');

  $libraries['cellular_mod'] = array(
    'title' => 'Cellular UI',
    'website' => 'http://dev-cellular.gotpantheon.com/cellular-ui',
    'version' => array(),
    'js' => array(
      $library . '/cellular_mod.min.js' => array(
        'scope' => 'footer',
      ),
    ),
    'css' => array(
      $library . '/css/cellular_mod.css' => array(
        'type' => 'file',
        'media' => 'screen',
      ),
    ),
  );

  return $libraries;
}

