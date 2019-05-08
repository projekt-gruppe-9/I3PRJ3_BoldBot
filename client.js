var socket = io('http://192.168.63.141:5000'); // Den IP som client skal oprette forbindelse til

socket.on('Forbindelse oprettet', function (data) {
    console.log("Der er hul igennem");
});


window.addEventListener("load", function(){


  var start = document.getElementById('start'); // Lytter på start knappen i HTML filen
  var stop = document.getElementById('stop'); // Lytter til stop knappen i HTML filen

  start.addEventListener('click', function() { // Ved trykket på start knappen, går denne funktion igang

      console.log("boldbot starter");
      socket.emit('start', { duration: 2 });

  });

  stop.addEventListener('click', function(){ // Ved tryk på stop knap, gå ind i denne funktion

    console.log("boldbot stopper");
    socket.emit('stop');
  })
});
