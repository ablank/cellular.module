/**
 * @file
 * Initiate Cellular UI.
 */

(function($) {

  Drupal.behaviors.cellular_mod = {
    attach: function(context, settings) {

      for (var element in settings.cellular_mod) {
        // CellularUI instance.
        var cell = $('.' + element);

        // lazyLoad support.
        if (settings.cellular_mod[element].settings.lazyLoad) {
          var images = cell.find('img');

          $.each(images, function(i, image) {
            $(image).attr('data-src', $(image).attr('src'));
          });

          images.addClass('lazy');
        }

        // Attach instance settings.
        cell.cellular_mod(settings.cellular_mod[element].settings);
/*
        // Set an inline height if custom AJAX pagination is enabled;
        // otherwise replacement of element  causes scrolling effect.
        if (settings.cellular_mod[element].views.ajax_pagination) {
          var owlnav = $('.' + element);
          owlnav.parent().css('height', owlnav.height());

          var view = owlnav.parent().parent();
          var next = $(view).find('.pager-next a', context);
          var prev = $(view).find('.pager-previous a', context);

          // Attach Cellular UI behaviors to pager elements.
          $(next).once('ajax', function() {
            $(next, context).click(function() {
              owlnav.trigger('owl.next');
            });
          });
          $(prev).once('ajax', function() {
            $(prev, context).click(function() {
              owlnav.trigger('owl.prev');
            });
          });
        }
*/
      }
    }
  };

}(jQuery));
