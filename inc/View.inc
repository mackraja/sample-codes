<?php
/**
 * Parent class : Object
 * Child class : View
 * @author : MontyKhanna
 * Created : 2015-10-20
 * Last Modified : 2015-10-24
 * @todo : 
 * 
 */

require_once ROOT . DS . CLASSES . DS . "lib" . DS . "Object.inc";

if(!class_exists("View")):
class View extends Object{

/**
 * Constructor
 * 
 * @property	1.) Set View Variables.
 * 			 	2.) Set Extention for view pages.
 * 				3.) Set Email
 * 				4.) Set Path for view pages.
 * 				5.) Set Extention and Path for view pages.
 * 				6.) Set Header
 * 				7.) Set Footer
 * 
 * @param array $array
 */
	public function View($array=[]){
		$this->setViewArr($array);
		$this->setExt();
		$this->setEmail();
		$this->setPath();
		$this->changeExtPath();
		$this->setHeader();
		$this->setFooter();
	}
	
	public function getViewArr() {
		return $this -> viewArr;
	}
	
	public function getLayout() {
		return $this -> layout;
	}
	
	public function getView() {
		return $this -> view;
	}
	
	public function getExt() {
		return $this -> ext;
	}
	
	public function getEmail() {
		return $this -> email;
	}
	
	public function getPath() {
		return $this -> path;
	}
	
	public function getError() {
		return $this -> error;
	}
	
	public function getContent(){
		include_once $this -> content;
	}
	
	public function getHeader(){
		include_once $this -> header;
	}
	
	public function getFooter(){
		include_once $this -> footer;
	}
	
	public function getElement(){
		if($this -> element != NULL)
		include_once $this -> element;
	}
	
	public function getPartial(){
		return $this -> partial;
	}
	
	public function setViewArr($viewArr = []) {
		$this -> viewArr = $viewArr;
	}
	
	public function setLayout($layout = NULL) {
		$this -> layout = $layout;
	}
	
	public function setView($view = NULL) {
		$this -> view = $view;
	}
	
	public function setExt($ext = NULL) {	
		$this -> ext = ($ext != NULL) ? $ext : (isset($this->viewArr['config']['ext']) ? $this->viewArr['config']['ext'] : $this -> getExt());
	}
	
	public function setEmail($email = NULL) {
		$this -> email = ($email != NULL) ? $email : (isset($this->viewArr['email']) ? $this->viewArr['email'] : $this -> getEmail());
	}
	
	public function setPath($path = NULL) {
		$this -> path = ($path != NULL) ? $path : (isset($this->viewArr['config']['path']) ? $this->viewArr['config']['path'] : $this -> getPath());
	}
	
	public function setError($error = NULL) {
		$this -> error = ($error != NULL) ? $error : $this -> getError();
	}
	
	public function setContent($default = NULL, $partial = NULL){
		$content = ($default != NULL) ? $default : $this->getView();
		if($content == 'error'){
			$ext = '.php';
		}else{
			$ext = $this->getExt();
		}
		$rootPath = ROOT.DS.$this->getPath().DS;
		$this->content = ($partial != NULL) ? $rootPath.'Partials'.DS.$content.'-'.$partial.'.php': $rootPath.$content.$ext;
	}
	
	public function setHeader($header = NULL){
		$headerPath = ROOT.DS.$this->getPath().DS.'Common'.DS;
		$this->header = ($header != NULL) ? $headerPath.$header.'.php' : $headerPath.$this->header.'.php';
	}
	
	public function setFooter($footer = NULL){
		$footerPath = ROOT.DS.$this->getPath().DS.'Common'.DS;
		$this->footer = ($footer != NULL) ? $footerPath.$footer.'.php' : $footerPath.$this->footer.'.php';
	}
	
	public function setElement($element = NULL){
		$this->element = ($element != NULL) ? ROOT.DS.$this->getPath().DS.'Elements'.DS.$element.".php" : $element;
	}
	
	public function setPartial($partial = NULL){
		$this->partial = ($partial != NULL) ? $partial : $this->getPartial();
	}
	
	public function layout($layout = NULL){
		if ($layout) {$this -> setLayout($layout);}
		return $this -> getLayout();
	}
	
	public function render($default = NULL, $partial = NULL){
		$rootPath = ROOT.DS.$this->getPath().DS;
		$fileExistPath = ($partial != NULL) ? $rootPath.'Partials'.DS.$default.'-'.$partial.'.php': $rootPath.$default.$this->getExt();
		$this->changeExtPath($default);
		if(isset($default)) {
			if(file_exists($fileExistPath)){
				$this->setContent($default,$partial);
			}elseif(file_exists($rootPath.$default.$this->getExt())){
				$this->setContent($default);
			}else{
				$this->setElement();
				$this->setContent($this->getError());
			}
		}else{
			$this->setContent($this->getView());			
		}
		require_once ROOT.DS.$this->getPath().DS."Layouts".DS.$this->getLayout().".php";
	}
	
	public function changeExtPath($default = NULL){
		$oldview = ($default != NULL) ? $default : $this->getView();
		$dir = scandir(ROOT);
		foreach ($dir as $dirValues){
			if(is_dir($dirValues) && $dirValues[0] != '.'){
				$a = scandir($dirValues);
				foreach ($a as $a_value){
					if($a_value[0] != '.' && ($oldview == current(explode(".", $a_value)))){
						$exp = explode('.',$a_value);
						rename(ROOT.DS.$dirValues.DS.$oldview.'.'.$exp[1], ROOT.DS.$dirValues.DS.$oldview.$this->getExt());
						rename(ROOT.DS.$dirValues,ROOT.DS.$this->getPath());
					}	// end nested if
				}	// end nested foreach
			}	// end if
		}	// end foreach
	}
	
}
endif;