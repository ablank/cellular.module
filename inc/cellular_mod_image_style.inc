<?php

/**
 * Implements hook_image_default_styles()
 */
function cellular_mod_image_default_styles() {
  $styles = array();
  $styles['cellular_avatar'] = array(
    'label' => 'Cellular: Avatar (180 x 180)',
    'effects' => array(
      array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 180,
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
      array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 180,
          'height' => 180,
        ),
        'weight' => 1,
      ),
    ),
  );

  $styles['cellular_banner'] = array(
    'label' => 'Cellular: Banner (800 x 200)',
    'effects' => array(
      array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
      array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 800,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
