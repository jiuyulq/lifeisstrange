//app.js
var qcloud = require('./vendor/wafer2-client-sdk/index')
var config = require('./config')

App({
    globalData:{
        appId:"wxaa3b9e554eae5f9d",
        secret:"dc2852e3946f84400aadcce4d872ee53",
        access_token: "10_EUz2WhWLKvYOQVzFuPeC-eykcaYOkSqdB-L3YZmmwNVJGdFmowy6-LglqEoePVsMGzICzJMgoDZ9LoOXJBdd3g15D4cj5mwqOry2GXUUw2YVUyOF59dLhWWao53KhR4cC4CzSzHrs0jKN1hKGDKaAEATQX",
        schedual_plans: [["骑行", "长江大桥", "2018-05-23", "00:00", "10分钟前"]],
    },
    onLaunch: function () {
        qcloud.setLoginUrl(config.service.loginUrl)
    }
})