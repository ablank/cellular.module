<?php
/**
 * @file
 * cellular_mod.theme.inc
 *
 * Implements theme functions for Cellular UI.
 */

/**
 * Template process carousel theme.
 */
function template_process_cellular_mod(&$vars) {
  $instance_id = $vars['settings']['instance'];
  $vars['settings']['attributes']['class'][] = $vars['settings']['id'];
}

/**
 * Theme declaration for Cellular UI wrapper.
 */
function theme_cellular_mod_wrapper($variables) {
  $attributes = $variables['output']['#settings']['attributes'];

  return '<div' . drupal_attributes($attributes) . '>' . drupal_render($variables['output']) . '</div>';
}

/**
 * Theme declaration for Cellular UI.
 */
function theme_cellular_mod($variables) {
  $instance = $variables['settings']['id'];
  $settings = $variables['settings'];
  $items = $variables['items'];

  $output = array(
    '#output' => array(
      'settings' => $settings,
      'items' => $items
    ),
    '#pre_render' => array('cellular_mod_pre_render_cache'),
  );

  return drupal_render($output);
}

/**
 * Construct element for render.
 */
function cellular_mod_pre_render_cache($element) {
  $settings = $element['#output']['settings']['instance'];
  $instance = $element['#output']['settings']['id'];

  $output = array(
    '#theme' => 'cellular_mod_list',
    '#items' => $element['#output']['items'],
    '#settings' => $element['#output']['settings']
  );

  // Load carousel settings from the instance id.
  $instance_settings = _cellular_mod_return_instance_settings($settings);

  // Provide legacy settings alter.
  drupal_alter('cellular_mod_settings', $instance_settings, $instance);

  // Element output /w attached.
  $element['#markup'] = cellular_mod_build($output);
  $element['#children'] = drupal_render($element['#markup']);
  $element['#attached'] = array(
    'js' => array(
      array(
        'data' => drupal_get_path('module', 'cellular_mod') . '/js/cellular_mod.settings.js',
        'type' => 'file',
        'scope' => 'footer'
      ),
      array(
        'data' => array('cellular_mod' => array(
            $instance => array(
              'settings' => $instance_settings,
              'views' => array(
                'ajax_pagination' => variable_get('cellular_mod_override_ajax_pagination_' . $settings)
              ),
            ),
          ),),
        'type' => 'setting'
      )
    ),
    'library' => array(
      array(
        'cellular_mod',
      )
    ),
  );

  // Provide alter before element is rendered.
  drupal_alter('cellular_mod_pre_render', $element);

  return $element;
}

/**
 * Build final output array.
 */
function cellular_mod_build($output) {
  return array(
    '#output' => $output,
    '#theme_wrappers' => array('cellular_mod_wrapper'),
  );
}

/**
 * Default theme implementation for lists
 */
function theme_cellular_mod_list(&$vars) {
  $items = &$vars['items'];
  $output = '<ul>';

  if (!empty($items)) {
    foreach ($items as $i => $item) {
      $output .= theme('cellular_mod_list_item', array(
        'item' => $item['row'],
        'class' => drupal_html_class('item-' . $i),
      ));
    }
  }
  $output .= '</ul>';
  
  //dpm($vars);
  return $output;
}

/**
 * Default theme implementation for cellular_mod items.
 */
function theme_cellular_mod_list_item(&$vars) {
  return '<li class="' . $vars['class'] . '">' . $vars['item'] . "</li>";
}
