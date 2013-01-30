<?php

/**
 * Widgets ajax call
 *
 */

/**
 * Register ajax calls by implementing hook_menu()
 *
 * @see http://api.drupal.org/api/drupal/modules%21system%21system.api.php/function/hook_menu/7
 * 
 * Expose hook_register_widgets_ajax_calls
 */
function widgets_menu() {
    return module_invoke_all('register_widgets_ajax_calls');
    /*
    return array(
        'path/to/call' => array(
            'page callback' => ...
            'access callback' => ...
            'type' => ...
        )
    );
    */
}