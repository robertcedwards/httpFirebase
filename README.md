Arduino to Firebase via Firebase-PHP
============
Arduino + Ethernet Shield = no-ssl support = no Firebase

Arduino + Ethernet Shield + FirebasePHP = Firebase!

You definitely need to make some changes to the script to make it work for your setup but this should get you started.
i.e. your Firebase url, whitelist your server's IP address, etc.

Build using the Firebase PHP library from: <br/>

[Firebase PHP Client](https://github.com/ktamas77/firebase-php) [![Build Status](https://drone.io/github.com/ktamas77/firebase-php/status.png)](https://drone.io/github.com/ktamas77/firebase-php/latest)


[Based on Firebase REST API](https://www.firebase.com/docs/rest-api.html)


Base library: @ktamas77
Token auth: @craigrusso
Update & Push method: @mintao
