function change_color() {
    var input_R = document.getElementById("R").value;
    var input_G = document.getElementById("G").value;
    var input_B = document.getElementById("B").value;
    
    document.getElementById("body").style.color = "rgb("+input_R.toString()+
    ","+input_G.toString()+","+input_B.toString()+")";
}

function change_border(){
  var input_W = document.getElementById("W").value;

  document.getElementById("body").style.borderWidth = input_W.toString() + "px";
}
function checkPassword() {
    var password = document.getElementById("ps").value;
    var password_check = document.getElementById("ps_check").value;
    if (password.length < 8) {
      alert("Password must be at least 8 characters long");
    }
    else {
      if (password == password_check) {
        alert("passwords match");
      }
      else {
        alert("passwords do not match");
      }
    }
    
  }