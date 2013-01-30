<?php

/**
 * A widget a page component that 
 * takes a defined number of arguments and a template 
 * and outputs a chunk of ordinary html markups
 *
 */

/**
 * Register widgets by implementing hook_theme()
 * @see http://api.drupal.org/api/drupal/modules%21system%21system.api.php/function/hook_theme/7
 * 
 * Expose hook_register_widgets
 */
function widgets_theme() {
    // expose hook_register_widgets
    return module_invoke_all('register_widgets');
    /*
    return array(
        'sample_widget' => array(
            'variables' => array(),
            'template' => 'tpl/sample_widget',
        )
    );
    */
}

/**
 * Render a widget
 * 
 * @param string $name The widget name registered in widgets_theme()
 * @param array $variables Arguments passed into the widget template
 * 
 * @return string HTML markup
 */
function widget($name, $variables=array()) {
    return theme($name, $variables);
}