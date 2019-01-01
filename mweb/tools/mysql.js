//调用mysql模块
var mysql = require('mysql');

//创建connection
var db_name = 'jiuyulq';
var connection = mysql.createConnection({
    host: 'jiuyulq.xyz', //主机
    user: 'root', //MySQL认证用户名
    password: 'crhope7913',
    database: 'jiuyulq',
    port: '3306'
});

connection.connect(function(err) {
    if (err) {
        console.log('query:' + err);
        return;
    } else {
        console.log('connection succeed.');
    }
})

module.exports = connection;
