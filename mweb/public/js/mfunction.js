var  pl_enter_name= "please enter your name";
var pl_enter_pwd = "please enter your password";

function loginCheck(){
  var name = $("#inputName").val();
  var password = $("#inputPwd").val();
  if(name == null || name == ""){
    //$("#inputNameMsg").html(pl_enter_name);
    return false;
  }

  if(password == null || password == ""){
    //$("#inputPwdMsg").html(pl_enter_pwd);
    return false;
  }

  return true;
}

function inputNameBlur(){
  var nameVal = $("#inputName").val();
  var nameMsgVal = $("#inputNameMsg").text();

  //如果为空  显示提示
  if(nameVal == null || nameVal == ""){
    $("#inputNameMsg").html(pl_enter_name);
  }

  //如果不为空 但有提示  则去掉提示
  if(nameVal != null && nameVal != "" && nameMsgVal != null & nameMsgVal != ""){
    $("#inputNameMsg").html("");
  }
}

function inputPwdBlur(){
  var pwdVal = $("#inputPwd").val();
  var pwdMsgVal = $("#inputPwdMsg").text();

  //如果为空  显示提示
  if(pwdVal == null || pwdVal == ""){
    $("#inputPwdMsg").html(pl_enter_pwd);
  }

  //如果不为空 但有提示  则去掉提示
  if(pwdVal != null && pwdVal != "" && pwdMsgVal != null & pwdMsgVal != ""){
    $("#inputPwdMsg").html("");
  }
}
