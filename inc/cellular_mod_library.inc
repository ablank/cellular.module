<?php

/**
 * Implements hook_library().
 */
function cellular_mod_library() {
  $lib_path = '';

  // GSAP: GreenSock Animation Platform
  $libraries['gsap'] = array(
    'title' => 'GreenSock Animation Platform',
    'website' => '',
    'version' => '',
    'js' => array(
      '/lib/gsap/minified/plugins/CSSPlugin.min.js' => array(),
      '/lib/gsap/minified/easing/EasePack.min.js' => array(),
      '/lib/gsap/minified/TweenLite.min.js' => array(),
      '/lib/gsap/minified/jquery.gsap.min.js' => array(),
    ),
    'dependencies' => array(
      array('system', 'jquery'),
    ),
  );

  // Overlay child.
  $libraries['three'] = array(
    'title' => 'THREE.js',
    'website' => '',
    'version' => 'r68',
    'js' => array(
    //cdnjs.cloudflare.com/ajax/libs/three.js/r68/three' => array(),
    ),
    'css' => array(
      $module_path . '/overlay-child.css' => array(),
    ),
  );

  // Snap SVG
  $libraries['snapsvg'] = array(
    'title' => 'Snap SVG',
    'website' => '',
    'version' => '0.3.0',
    'js' => array(
      '/lib/snap.svg.js' => array(),
    ),
  );

  // Smoove.
  $libraries['smoove'] = array(
    'title' => 'Smoove',
    'website' => '',
    'version' => '0.3.0',
    'js' => array(
      '/lib/jquery.smoove.min.js' => array(),
    // '//cdnjs.cloudflare.com/ajax/libs/jquery-smoove/0.2.6/jquery.smoove.min.js'
    ),
  );

  // Prism.
  $libraries['prism'] = array(
    'title' => 'Prism',
    'website' => '',
    'version' => '0.0.1',
    'js' => array(
      '/lib/prism.min.js' => array(),
    ),
    'css' => array(
      '/lib/css/prism.css' => array(),
    ),
  ); // '//cdnjs.cloudflare.com/ajax/libs/prism/0.0.1/prism.min.js'
  //
  //
  // NProgress.
  $libraries['nprogress'] = array(
    'title' => 'NProgress',
    'website' => '',
    'js' => array(
      '/lib/nprogress.js' => array(),
    ),
    'css' => array(
      '/lib/css/nprogress.css' => array(),
    ),
  );
  // NProgress
  $libraries['migrate'] = array(
    'title' => 'Migrate',
    'website' => '',
    'version' => '1.2.1',
    'js' => array(
      '/lib/jquery.migrate.min.js' => array(),
    ),
  );
  // jParallax.
  $libraries['jparallax'] = array(
    'title' => 'jParallax',
    'website' => '',
    'version' => '2.0',
    'js' => array(
      '/lib/jquery.parallax.min.js' => array(),
    ),
  );

  // Flowtype.
  $libraries['flowtype'] = array(
    'title' => 'Flowtype',
    'website' => '',
    'version' => '',
    'js' => array(
      '/lib/jquery.flowtype.min.js' => array(),
    ),
  );
  // Freetile.
  $libraries['freetile'] = array(
    'title' => 'Freetile',
    'website' => '',
    'version' => '',
    'js' => array(
      '/lib/jquery.freetile.min.js' => array(),
    ),
  );

  // D3.
  $libraries['d3'] = array(
    'title' => 'D3',
    'website' => '',
    'version' => '',
    'js' => array(
      '/lib/d3.min.js' => array(),
    ),
  );

  // Backstretch.
  $libraries['backstretch'] = array(
    'title' => 'Backstretch',
    'website' => '',
    'version' => '2.0.4',
    'js' => array(
      '/lib/jquery.backstretch.min.js' => array(),
    ),
  );
  /* // child.
    $libraries['child'] = array(
    'title' => 'Child',
    'website' => '',
    'version' => '',
    'js' => array(
    $module_path . '/child.js' => array(),
    ),
    'css' => array(
    $module_path . '/child.css' => array(),
    ),
    );
   */

  return $libraries;
}
