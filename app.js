var app = require('http').createServer(handler)
var io = require('socket.io')(app)
var url = require('url')
var fs = require('fs')

var exec = require('child_process').execFile;
var ps = require('ps-node');


//Åbner port 5000 på ens browser.
app.listen(5000);


// Http functionen
function handler (req, res) {

    // Oprettere URL til browser
    var path = url.parse(req.url).pathname;

    // Load index fil til website
    if (path == '/') {
        index = fs.readFile('/home/stud/projekt3/src/host/libpixyusb2_examples/get_blocks_cpp_demo/public/index.html',
            function(error,data) {

                if (error) {
                    res.writeHead(500);

                    return res.end("Error: unable to load index.html");
                }

                res.writeHead(200,{'Content-Type': 'text/html'});
                res.end(data);
            });
    // Path til javascript fil
    } else if( /\.(js)$/.test(path) ) {
        index = fs.readFile('/home/stud/projekt3/src/host/libpixyusb2_examples/get_blocks_cpp_demo/public/js/client.js',
            function(error,data) {

                if (error) {
                    res.writeHead(500);
                    return res.end("Error: unable to load " + path);
                }

                res.writeHead(200,{'Content-Type': 'text/plain'});
                res.end(data);
            });
    } else {
        res.writeHead(404);
        res.end("Error: 404 - File not found.");
    }
}

// Opretter forbindelse til websocket
io.sockets.on('connection', function (socket) {

  // Håndtere modtagne beskeder fra clienten
  socket.on('start', function(data) {
        console.log("det virker");
        exec('/home/stud/projekt3/src/host/libpixyusb2_examples/get_blocks_cpp_demo/myExe', function (err, data){
          console.log(err);
          console.log(data.toString());
        });

        delay = data["duration"];
      setTimeout(function(){
        socket.emit("");
      });
  });

  socket.on('stop', function(data){
    console.log("Program stopper");
    ps.lookup({
        command: 'myExe',
        psargs: 'ux'
        }, function(err, resultList ) {
        if (err) {
            throw new Error( err );
        }

        resultList.forEach(function( process ){
            if( process ){
                console.log( 'PID: %s, COMMAND: %s, ARGUMENTS: %s', process.pid, process.command, process.arguments );
                var pid1 = process.pid;
                console.log('Dette er PID for programmet der er igang: %d' ,pid1);
                ps.kill( process.pid, {

                   signal: 'SIGKILL',
                   timeout: 10,  // Delay hvis programmet ikke exites inden den går videre.
               }, function(){});
            }
        });
    });
  })

});
