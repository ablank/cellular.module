<?php
/**
 * Return list of setting variables.
 */
function _cellular_mod_return_setting_vars() {
  $query = 'SELECT name FROM {variable} WHERE name LIKE :name';
  $results = db_query($query, array(':name' => db_like('cellular_mod_') . '%'))->fetchAll();

  return $results;
}