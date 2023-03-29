<?php
class jdt{
 public $link='';
 function __construct($duration, $remarks){
  $this->connect();
  $this->storeInDB($duration, $remarks);
 }
 
 function connect(){
  $this->link = mysqli_connect('localhost','root','') or die('Cannot connect to the DB');
  mysqli_select_db($this->link,'arduino') or die('Cannot select the DB');
 }
 
 function storeInDB($duration, $remarks){
  $query = "insert into jobdurationtimer set duration='".$duration."', remarks='".$remarks."'";
  $result = mysqli_query($this->link,$query) or die('Errant query:  '.$query);
  if($result === TRUE){echo "Data Tersimpan";}else{echo "Gagal Menyimpan data";}
 }
 
}
if($_GET['dataDuration'] != '' and  $_GET['dataRemarks'] != ''){
 $jdt=new jdt($_GET['dataDuration'],$_GET['dataRemarks']);
}

?>
