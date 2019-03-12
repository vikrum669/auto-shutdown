<?php

$executionStartTime = microtime(true);
    //make sure the script has enough time to run (300 seconds  = 5 minutes)
    ini_set('max_execution_time', '300');
    ini_set('set_time_limit', '0');
    function Compress(){
        try {
        $target = isset($_GET["targetname"]) ? $_GET["targetname"] : 'archive.tar'; //default to archive.tar
        $dir = isset($_GET["dir"]) ? $_GET["dir"] : './.'; //defaults to all in current dir
        //setup phar
        $phar = new PharData($target);
        $phar->buildFromDirectory(dirname(__FILE__) . '/'.$dir);

        $phar->Compress(Phar::GZ);
        unlink('archive.tar');
        echo 'Compressing all files done, check your server for the file ' .$target;
      } catch (Exception $e) {
        // handle errors
        echo 'An error has occured, details:';
        echo $e->getMessage();
      }
    }


   // Compress();
   $filename="/home/mark/Downloads/Backups/DontDelete/uts.zip";
  // echo filesize($filename)/1024/1024 . ' MB';

   $executionEndTime = microtime(true);

   echo $executionEndTime; 

   $time=$executionEndTime-$executionStartTime;

   echo "\nExecution time in second= ". $time*0.000001;
?>