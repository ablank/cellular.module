<?php

/**
 * Implements hook_date_formats().
 */
function cellular_mod_date_formats() {
  return array(
// Creates a new format for a new, custom format type.
    array(
      'type' => 'cellular_formal_0',
      'format' => 'j F, Y',
      'locales' => array(),
    ),
    array(
      'type' => 'cellular_formal_1',
      'format' => 'F j, Y',
      'locales' => array(),
    ),
    array(
      'type' => 'cellular_abbr_month',
      'format' => 'M',
      'locales' => array(),
    ),
    array(
      'type' => 'cellular_abbr_day',
      'format' => 'D',
      'locales' => array(),
    ),
    array(
      'type' => 'cellular_month',
      'format' => 'F',
      'locales' => array(),
    ),
    array(
      'type' => 'cellular_day',
      'format' => 'l',
      'locales' => array(),
    ),
    array(
      'type' => 'cellular_date',
      'format' => 'j',
      'locales' => array(),
    ),
    array(
      'type' => 'cellular_time_0',
      'format' => 'g:i',
      'locales' => array(),
    ),
    array(
      'type' => 'cellular_time_1',
      'format' => 'g:i a',
      'locales' => array(),
    ),
    // Override core's format types.
    array(
      'type' => 'short',
      'format' => 'm-j-Y',
      'locales' => array(),
    ),
    array(
      'type' => 'medium',
      'format' => 'g:i D. M. j',
      'locales' => array(),
    ),
    array(
      'type' => 'long',
      'format' => 'g:i, l F j Y',
      'locales' => array(),
    ),
  );
}

/**
 * Implements hook_date_format_types().
 */
function cellular_mod_date_format_types() {
  return array(
    'cellular_formal_0' => t('Formal, Date 1st'),
    'cellular_formal_1' => t('Formal Date 2nd'),
    'cellular_month' => t('Month'),
    'cellular_abbr_month' => t('Abbr. Month'),
    'cellular_day' => t('Day'),
    'cellular_abbr_day' => t('Abbr. Day'),
    'cellular_date' => t('Date'),
    'cellular_time_0' => t('Time'),
    'cellular_time_1' => t('Specific Time'),
  );
}
