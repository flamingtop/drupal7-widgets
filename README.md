# widget() for Drupal(7)

In Drupal, blocks are the smallest managable components. If you want
something somewhere in a page, you make a block and render it into the
desired place(region) by implementing hook\_block\_view().

This module adds an extra layer called "widgets" and delegates HTML
rendering to each widget, this allows you to treat blocks as simple
containers.

    ------------------
    |  region        |
    |  ------------- |
    |  |  block    | |
    |  |  -------- | |
    |  |  |widget| | |
    |  |  -------- | |
    |  |           | |
    |  ------------- |
    ------------------
    
    function my_module_block_view($delta='') {
        return array(
            'subject' => NULL,
            'content' => widget('my_widget', array('param' => ...)) // delegate rendering
        );
    }

## How to Use

* declare new widgets

        function my_module_register_widgets() {
            return array(
                'my_widget' => array(
                    'variables' => array('title' => 'Default Widget Title'), # default parameters passed into the template
                    'template' => drupal_get_path('module', 'my_module') . '/tpl/my_widget',
                ),
            );
        }
    
* render a widget

        $my_widget = widget('my_widget', array('title' => 'My Widget Title'));
        or
        echo widget('my_widget', array('title' => 'My Widget Title'));

* declare widgets calls

    Some widgets might need to ingeract with the server,
    hook\_register\_widgets\_calls() is a simple wrapper to hook_menu

        function my_module_register_widgets_calls() {
            return array(
                'path/to/call' => array(
                    'page callback' => ...
                    'access callback' => ...
                    'type' => ...
                ),
            );
        }
    
    
