// pages/plan/plan.js

var app = getApp();
Page({

    /**
     * 页面的初始数据
     */
    data: {
        title: '',
        start_time: 'time',
        start_date: 'date',
        end_time: 'time',
        end_date: 'date',
        location: '',
        notificationArray: ['1小时', '2小时', '24小时', '1周', '2周', '1月'],
        objectnotificationArray: [
            {
                id: 0,
                name: '1小时'
            },
            {
                id: 1,
                name: '2小时'
            },
            {
                id: 2,
                name: '24小时'
            },
            {
                id: 3,
                name: '1周'
            },
            {
                id: 4,
                name: '2周'
            },
            {
                id: 5,
                name: '1月'
            },],
        notificationIndex: 0,
    },

    planStartDateChange: function (e) {
        this.setData({
            start_date: e.detail.value
        })
    },
    planStartTimeChange: function (e) {
        this.setData({
            start_time: e.detail.value
        });
    },
    planEndDateChange: function (e) {
        this.setData({
            end_date: e.detail.value
        })
    },
    planEndTimeChange: function (e) {
        this.setData({
            end_time: e.detail.value
        });
    },
    planNotiChange: function (e) {
        this.setData({
            notificationIndex: e.detail.value
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
    formReset: function (e) {
        this.setData({
            notificationIndex: 0,
            start_time: 'time',
            start_date: 'date',
            end_time: 'time',
            end_date: 'date',
        })
    },
    formSubmit: function (e) {
        app.globalData.schedual_plans.push([
            this.data.title,
            this.data.location,
            this.data.start_date,
            this.data.start_time,
            this.data.end_date,
            this.data.end_time,
            this.data.notificationArray[this.data.notificationIndex]]);
        //console.log(app.globalData.schedual_plans);

        wx.switchTab({
            url: '/pages/index/index',
        })

    },

    /**
     * 生命周期函数--监听页面加载
     */
    onLoad: function (options) {

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