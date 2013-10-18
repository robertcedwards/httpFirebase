<?php
require_once 'firebaseLib.php';
// --- This is your Firebase URL
$url = 'YOUR FIREBASE URL';
// --- Use your token from Firebase here
$token = 'YOUR TOKEN HERE';
// --- Here is your parameter from the http GET
$arduino_data = $_GET['arduino_data'];
// --- Set up your Firebase url structure here
$firebasePath = '/';

/// --- Making calls
$fb = new fireBase($url, $token);
$response = $fb->set($firebasePath, $rfidid);

sleep(2);
