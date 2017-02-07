<?php

/**
 * @file
 * cellular_mod.theme.inc
 *
 * Implements block content for Cellular Module.
 */
function cellular_mod_block_info() {
// DRUPAL_CACHE_PER_ROLE will be assumed.
  $blocks['cellular_social_follow'] = array(
    'info' => t('Cellular: Social Media Following'),
  );
  $blocks['cellular_social_share'] = array(
    'info' => t('Cellular: Social Media Sharing'),
  );
  $blocks['cellular_user_links'] = array(
    'info' => t('Cellular: User Links'),
  );
  $blocks['cellular_main_menu'] = array(
    'info' => t('Cellular: Main Menu'),
  );
  $blocks['cellular_copyright'] = array(
    'info' => t('Cellular: Copyright'),
  );

  return $blocks;
}

function cellular_mod_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'cellular_social_follow':
      //$block['subject'] = t('Follow Us');
      $block['content'] = array(
        '#type' => 'markup',
        '#title' => NULL,
        '#markup' => '<div class="jSocial follow"></div>'
//'#nodes' => $nodes,
      );
      break;
    case 'cellular_social_share':
      //$block['subject'] = t('Share this page');
      $block['content'] = array(
        '#type' => 'markup',
        '#title' => NULL,
        '#markup' => '<div class="jSocial share"></div>'
//'#nodes' => $nodes,
      );
      break;
    case 'cellular_main_menu':
      //$block['subject'] = t('Main Menu');
      $block['content'] = array(
        '#type' => 'markup',
        '#title' => NULL,
        '#markup' => '<div id="main-menu">' . cellular_mod_main_menu() . '</div>',
      //'#nodes' => $nodes,
      );
      break;
    case 'cellular_user_links':
      //$block['subject'] = t('User Links');
      $block['content'] = array(
        '#type' => 'markup',
        '#title' => NULL,
        '#markup' => cellular_mod_user_link(),
      //'#nodes' => $nodes,
      );
      break;

    case 'cellular_copyright':
      //$block['subject'] = t('Copyright');
      $copy = date("Y") . " " . variable_get('site_name', 'Drupal');
      $block['content'] = array(
        '#type' => 'markup',
        '#title' => NULL,
        '#markup' => '<small id="copyright">&copy; ' . $copy . '</small>',
      );
      break;
  }
  return $block;
}
