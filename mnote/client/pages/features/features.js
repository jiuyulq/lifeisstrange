// pages/feature/feature.js
Page({

  /**
   * 页面的初始数据
   */
  data: {

  },

  addSchedual: function () {
    wx.navigateTo({
      url: '/pages/schedual/schedual',
    })
  },
  addPlan: function () {
    wx.navigateTo({
      url: '/pages/plan/plan',
    })
  },
  addInsNotes: function () {
    wx.navigateTo({
      url: '/pages/insnotes/insnotes',
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    //测试-begin
    // wx.navigateTo({
    //   url: '/pages/schedual/schedual',
    // })
    //测试-end
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