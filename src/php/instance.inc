<?php
/**
 * Return Cellular UI settings array or default.
 *
 * @param string $instance
 *  Carousel instance settings machine name.
 */
function _cellular_mod_return_instance_settings($instance = 'cellular_mod_settings_default') {
   dpm($instance);
  if ($settings_cache = cache_get('cellular_mod_' . $instance['settings'])) {
    $settings = $settings_cache->data;
  }
  else {
    $settings = array(
      'items' => (int) variable_get('cellular_mod_items_' . $instance['settings']),
    );

    // Update settings cache.
    cache_set('cellular_mod_' . $instance['settings'], $settings, 'cache');
  }

  return $settings;
}

/**
 * Return array with key pair.
 */
function cellular_mod_instance_callback_list() {
  $instances = _cellular_mod_return_instances();

  // Format array as callback option list.
  foreach ($instances as $instance) {
    $content[$instance->name] = $instance->name;
  }

  return $content;
}

/**
 * Helper function, return active instances by name.
 */
function _cellular_mod_return_instances($name = FALSE) {
  $query = 'SELECT name FROM {variable} WHERE name LIKE :name';

  if (!$name) {
    $results = db_query($query, array(':name' => db_like('cellular_mod_settings_') . '%'))->fetchAll();
  }
  else {
    $results = db_query($query, array(':name' => $name))->fetchField();
  }

  return $results;
}
