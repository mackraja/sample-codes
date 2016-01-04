<?php
/**
 * Parent class : Object
 * @abstract : Object
 * @author : MontyKhanna
 * Created : 2015-10-20
 * Last Modified : 2015-10-24
 * @todo : 
 *
 */
abstract class Object{

/**
 * Contains variables to be handed to the view.
 *
 * @var array
 */
	public $viewArr = [];
	
/**
 * The name of the layout file to render the view inside of. The name specified
 * is the filename of the layout in /Views/layouts without extension.
 *
 * @var string
 */
	public $layout = 'layout_1';
	
/**
 * The name of the view file to render. The name specified
 * is the filename in /Views without extension.
 *
 * @var string
 */
	public $view = 'about';
	
/**
 * File extension for view templates. Defaults ".php".
 *
 * @var string
 */
	public $ext = '.php';
	
/**
 * The email of the Object.
 *
 * @var string
 */
	public $email = 'mkmontykhanna@gmail.com';
	
/**
 * The name of the views subfolder containing views for this controller.
 *
 * @var string
 */
	public $path = 'Views';
	
/**
 * The name of error page.
 *
 * @var string
 */
	public $error = 'error';
	
/**
 * The name of content page.
 *
 * @var string
 */
	public $content = NULL;
	
/**
 * The name of header page.
 *
 * @var string
 */
	public $header = 'header';
	
/**
 * The name of footer page.
 *
 * @var string
 */
	public $footer = 'footer';
	
/**
 * The name of element page.
 *
 * @var string
 */
	public $element = NULL;
	
/**
 * The name of partial variable.
 *
 * @var string
 */
	public $partial = NULL;
	
/**
 * 
 * @return array
 */		
	public function getViewArr() {}
	
/**
 *
 * @return string
 */	
	public function getLayout() {}

/**
 *
 * @return string
 */
	public function getView() {}
	
/**
 *
 * @return string
 */
	public function getExt() {}
	
/**
 *
 * @return string
 */
	public function getEmail() {}
	
/**
 *
 * @return string
 */
	public function getPath() {}
	
/**
 *
 * @return string
 */
	public function getError() {}
	
/**
 *
 * Include content Page
 */
	public function getContent() {}
	
/**
 *
 * Include Header Page
 */
	public function getHeader() {}
	
/**
 *
 * Include Footer Page
 */
	public function getFooter() {}
	
/**
 *
 * Include Element Page
 */
	public function getElement() {}
	
/**
 *
 * @return string
 */
	public function getPartial() {}
	
/**
 * Set the view constructor variable in $viewArr
 * @param array $viewArr
 */
	public function setViewArr($viewArr = []) {}

/**
 * set layout of page
 * @param string $layout
 */
	public function setLayout($layout = NULL) {}

/**
 * set view page
 * @param string $view
 */
	public function setView($view = NULL) {}
	
/**
 * set view page extension
 * @param string $ext
 */
	public function setExt($ext = NULL) {}
	
/**
 * set email
 * @param string $email
 */
	public function setEmail($email = NULL) {}
	
/**
 * set view files parent directory name.
 * @param string $path
 */
	public function setPath($path = NULL) {}
	
/**
 * set error page
 * @param string $error
 */
	public function setError($error = NULL) {}

/**
 * set content page
 * @param string $default, string $partial
 */
	public function setContent($default = NULL, $partial = NULL) {}
	
/**
 * set header page
 * @param string $header
 */
	public function setHeader($header = NULL) {}
	
/**
 * set footer page
 * @param string $footer
 */
	public function setFooter($footer = NULL) {}
	
/**
 * set element page
 * @param string $element
 */
	public function setElement($element = NULL) {}
	
/**
 * set view page with partial variable
 * @param string $partial
 */
	public function setPartial($partial = NULL) {}
	
/**
 *
 * @param string $layout
 * @return string
 */	
	public function layout($layout = NULL) {}
	
/**
 * Include Layout page and set view page
 * @param string $default, string $partial
 */
	public function render($default = NULL, $partial = NULL) {}
	
/**
 * Rename the file extention and file parent directory name.
 * @param string $default
 */
	public function changeExtPath($default = NULL) {}
}