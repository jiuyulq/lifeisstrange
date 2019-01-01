// pages/schedual/schedual.js

var app = getApp();
Page({

    /**
     * 页面的初始数据
     */
    data: {
        openid:'',
        title:'',
        time: 'time',
        date: 'date',
        location:'',
        notificationArray: ['无', '日程开始时', '5分钟前', '10分钟前', '15分钟前', '20分钟前', '30分钟前', '1小时前'],
        objectnotificationArray: [
            {
                id: 0,
                name: '无'
            },  
            {
                id: 1,
                name: '日程开始时'
            },
            {
                id: 2,
                name: '5分钟前'
            },
            {
                id: 3,
                name: '10分钟前'
            },
            {
                id: 4,
                name: '15分钟前'
            },
            {
                id: 5,
                name: '20分钟前'
            },
            {
                id: 6,
                name: '30分钟前'
            },
            {
                id: 7,
                name: '1小时前'
            },],
        notificationIndex: 0,
    },

    schedualDateChange: function (e) {
        this.setData({
            date: e.detail.value
        })
    },
    schedualTimeChange: function (e) {
        this.setData({
            time: e.detail.value
        });
    },
    schedualNotiChange: function (e) {
        this.setData({
            notificationIndex:e.detail.value
        });
    },
    titleInput:function(e){
        this.setData({
            title:e.detail.value,
        });
    },
    locationInput:function(e){
        this.setData({
            location:e.detail.value,
        });
    },
    formReset:function(e){
        this.setData({
            notificationIndex:0,
            time: 'time',
            date: 'date'
        })
    },
    formSubmit:function(e){
        console.log(e);

        //模版消息
        /*
        wx.showLoading({ //期间为了显示效果可以添加一个过度的弹出框提示“加载中”
            title: '加载中',
            icon: 'loading',
        });

        var d = {
            "keyword1": {
                "value": this.data.title,
                "color": "#4a4a4a"
            },
            "keyword2": {
                "value": this.data.date,
                "color": "#9b9b9b"
            },
        };

        console.log(d)
        wx.request({
            url: 'https://api.weixin.qq.com/cgi-bin/message/wxopen/template/send?access_token=' + getApp().globalData.access_token,
            　　　　　//注意不要用value代替data
            data: {
                touser: this.data.openid,
                template_id: 'Wcs5v1RkAEmDz1e6VSZSAiuJ9Mth-y1unRszJ9n1rME',//申请的模板消息id，
                page: '/pages/schedual/schedual',
                form_id: e.detail.formId,
                data: d,
                color: '#ccc',
                emphasis_keyword: 'keyword1.DATA'
            },
            method: 'POST',
            success: function (res) {
                wx.hideLoading();
                console.log("发送成功");
                console.log(res);
            },
            fail: function (err) {
                // fail
                console.log("push error")
                console.log(err);
            }
        });
        */


        // 计划数据存储
        app.globalData.schedual_plans.push([
            this.data.title,
            this.data.location,
            this.data.date,
            this.data.time,
            this.data.notificationArray[this.data.notificationIndex]]);
        console.log(app.globalData.schedual_plans);

        wx.switchTab({
            url: '/pages/index/index',
        })
    },

    /**
     * 生命周期函数--监听页面加载
     */
    onLoad: function (options) {
        var that = this;
        wx.login({
            success: (res) => {
                if (res.code) {
                    wx.request({
                        url: "https://api.weixin.qq.com/sns/jscode2session",
                        data: {
                            appid: getApp().globalData.appId,//你的appid
                            secret: getApp().globalData.secret,//你的secret
                            js_code: res.code,
                            grant_type: "authorization_code"
                        },
                        success: (res) => {
                            console.log(res);
                            that.setData({
                                openid: res.data.openid //存储openid
                            })
                        }
                    })
                }
            }
        })
    },

    /**
     * 生命周期函数--监听页面初次渲染完成
     */
    onReady: function () {

    },

    /**
     * 生命周期函数--监听页面显示
     */
    onShow: function () {

    },

    /**
     * 生命周期函数--监听页面隐藏
     */
    onHide: function () {

    },

    /**
     * 生命周期函数--监听页面卸载
     */
    onUnload: function () {

    },

    /**
     * 页面相关事件处理函数--监听用户下拉动作
     */
    onPullDownRefresh: function () {

    },

    /**
     * 页面上拉触底事件的处理函数
     */
    onReachBottom: function () {

    },

    /**
     * 用户点击右上角分享
     */
    onShareAppMessage: function () {

    }
})