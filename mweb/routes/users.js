var express = require('express');
var router = express.Router();

router.all('/login',function(req,res){
  // console.log(req);
  console.log(req.body.name);
  console.log(req.body.password);
  // res.send("login ...");

    var connection = require("../tools/mysql.js");
    var sql = "select user_pwd from mweb_users where user_name = '" + req.body.name + "'";

    connection.query(sql, function(error, results,fields){
        if(error) throw error;

        if(results.length == 0){
          console.log("user not found");
        }else if(results[0].user_pwd.equals(req.body.password)){
          console.log("login succeed");
          res.send("../public/index.html");
        }else{
          console.log("login failed.");
        }
        console.log("login result:" + results);
    })
});

//查询数据库
router.get('/query', function(req, res) {
    var connection = require('../tools/mysql.js');

    connection.query("select * from mkbook", function(error, results, fields){
        if(error) throw error;

        console.log('the results is:', results[0]);
        console.log('the results is:', results[0].id);
        console.log('the results is:', results[0].site);
    });

    res.send("query completed.");
});


//=====test part begin
router.all('/list', function(req, res) {
    console.log('-------')
    console.log(req.method);
    console.log(req.baseUrl);
    console.log(req.path);

    //获取某一请求头
    console.log(req.headers['user-agent']);
    console.log(req.get('user-agent'));

    //获取url查询参数
    console.log(req.query);
    //获取url查询参数值
    console.log(req.query.id);

    //post请求时，获取body中的参数值
    console.log(req.body);
    console.log(req.body.id);

    res.send('hello');
});

//    /users/120
router.get('/:id', function(req, res) {
    console.log('-------');
    //rest风格
    console.log(req.params.id);
    res.send('ok');
});


router.get('/fb', function(req, res) {
    res.status(403).send('(┬＿┬) forbidden!');
});

router.get('/tt', function(req, res) {
    res.contentType('application/javascript');
    res.sendFile('/js/bootstrap.js', {
        root: __dirname + '/../public'
    })
});

router.get('/mm', function(req, res) {
    res.json({
        a: 1,
        b: [true, 'ok']
    });
});
//=====test part end

module.exports = router;
