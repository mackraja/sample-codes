<?php
/**
 * On every request this index.php will call first.
 * 
 * @author : MontyKhanna
 * Created : 2015-10-20
 * Last Modified : 2015-10-24
 * @todo :
 *
 */

// Display Error
// ini_set('display_errors', 1);
// ini_set('display_startup_errors', 1);
// error_reporting(E_ALL);

// Define Constants
define ('DS', "/");
define ('CLASSES', "inc");
define('ROOT', dirname(__FILE__));

// Include View Class
require_once ROOT . DS . CLASSES . DS . "View.inc";

// create view component instance
$view = new View([
		'email' => 'montykhanna007@hotmail.com',	// set email
		'config' => [
				'ext' => '.jsp',	// set extension for view files. Example : .jsp, .ctp, .html, .php
				'path' => "Test"	// set views folder path
		]
	]);

// Set Layout for view pages.
$view->layout('layout_2');

// Set Element for view pages.
$view->setElement('sample');

// Set Partial page
$view->setPartial('banner');

// Set Render Variable
$render = (end(explode('/',$_SERVER['REQUEST_URI'])) == NULL) ? $view->getView() : end(explode('/',$_SERVER['REQUEST_URI']));

// Set Render Page
$view->render($render,$view->getPartial());