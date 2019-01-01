var express = require('express');
var bodyParser = require('body-parser');

var app = express();

//json类型body
app.use(bodyParser.json());
//query string类型body
app.use(bodyParser.urlencoded({
    extended: false
}));

//静态类型目录
app.use(express.static(__dirname + '/public'));
app.use('/', express.static(__dirname + '/public/index'));

// 路由与业务逻辑
// app.get('/', function(req, res){
//     res.send("hello");
// });
app.use('/users', require('./routes/users.js'));

app.listen(80);
