// pages/index/index.js
var app = getApp();
Page({

  /**
   * 页面的初始数据
   */
  data: {
    Year:'',
    Month:'',
    Day:'',
    Hour:'',
    Minute:'',
    Second:'',
    schedual_plans: [],
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

    //测试-begin
    // wx.navigateTo({
    //   url: '/pages/insnotes/insnotes',
    // })
    //测试-end

    // deprecated now
    // wx.getUserInfo({
    //   success: function (res) {
    //     var city = userInfo.city;
    //     var country = userInfo.country;
    //   },
    //   fail:function(res){
        
    //   }
    // });

    //this.data.schedual_plans = app.globalData.schedual_plans;

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
      this.setData({
          schedual_plans: app.globalData.schedual_plans,
      });

      console.log("index.js:");
      console.log(this.data.schedual_plans)

      var prntDate = new Date();
      this.setData({
          Year: prntDate.getFullYear(),
          Month: prntDate.getMonth() + 1,
          Day: prntDate.getDate(),
          Hour: prntDate.getHours(),
          Minute: prntDate.getMinutes(),
          Second: prntDate.getSeconds()
      });

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
  
  },

  /**
   * 跳转到features页码
   */
  jumpToFeatures:function(){
      wx.navigateTo({
        url: '/pages/features/features',
      })
  }
})