const char sito_html[] PROGMEM = R"=====(
<!DOCTYPE HTML>
	<html>
	<head>
	 <title>SIMATIC&nbsp;300&nbsp;Station</title>
	 <meta http-equiv="content-type" content="text/html; charset=UTF-8">	<!-- ISO-8859-1 oder UTF-8 -->
	 <meta http-equiv="cache-control" content="no-cache">
	 <meta http-equiv="pragma" content="no-cache">
	 <meta http-equiv="expires" content="0">
	 
	 <style type="text/css">
	 <!--
	  /*  ... CSS vrwenden wir, damit Anzeige in Standard-Browsern ebenfalls gut aussieht, Panel ignoriert das ... */
	  body { margin:0px; padding:0px;}
	  body {font-family: Arial, 'sans-serif'; font-size: 10pt;}
	  .Logon_Button_Basic {margin:0px;padding:0px;border:0px;height:19px;background-color:transparent;cursor:pointer;}
	  button span {text-decoration:underline;font-size:11pt;font-family:Arial;}
	  #logout_form_basic {margin:0px;padding:0px;}
	  .Login_Input_Fields {margin:0px;padding:1px 0px;border:0px;background-color:#CCCCFF;width:150px;}
	 -->
	 </style>
	</head>
	<!-- Rand ausschalten für alle, auch alte IE Browser und Netscape -->
	<body bgcolor="#ffffff" text="#000000" link="#0000ff" alink="#0000ff" vlink="#0000ff" >
	<basefont size="3" face="Arial"> <!-- Anzeige auf normalem PC ohne Serifen -->
	<!-- Titelbereich -->
	<table width="100%" border="0" cellspacing="3" cellpadding="0" bgcolor="#000053">
	 <tr>
		<td><font color="#ffffff" size="3">SIMATIC&nbsp;300&nbsp;Station/CPU&nbsp;315-2&nbsp;PN/DP</font></td>
		
     
	 <td align="right">
	  
		  
		 </td>
	  
	</tr>
	</table>
	<!-- Inhalt -->
	
    <table width="100%" border="0" cellspacing="0" cellpadding="1">
	 <tr> <!-- Abstand -->
      <td height="15"></td>
      <td></td>
     </tr>
     <tr>
      <td width="1">&nbsp;</td>
      <td><font size="2"><b>Log in</b></font></td>
     </tr>
     <tr><td height="6"></td><td></td></tr>  <!-- Abstand -->
    </table>
    <table border="0" cellspacing="0" cellpadding="0">
     <tr><td>
       <form action="/" method="post" id="Login_Area_Form" Name="LoginForm">

         <table width="100%" border="0" cellspacing="0" cellpadding="1">
		  <tr> 
           <td width="1">&nbsp;</td>		   
           <td><font size="2">Name</font></td>
		   <td width="20"></td>
           <td><input type="text" name="Login" class="Login_Input_Fields"></td>
          </tr>
          <tr> <!-- Abstand -->
           <td height="4"></td>
           <td></td>
           <td></td>
           <td></td>
          </tr>  
          <tr>
           <td width="1">&nbsp;</td>		   
           <td><font size="2">Password</font></td>
		   <td width="20"></td>
           <td><input type="password" name="Password" class="Login_Input_Fields"></td>
          </tr>
          <tr> <!-- Abstand -->
           <td height="4"></td>
           <td></td>
           <td></td>
		   <td></td>
          </tr>  
          <tr>
           <td width="1">&nbsp;</td>		   
           <td></td>
           <td></td>
           <!--<td><button type="submit" class="Logon_Button_Basic">Log in</button></td>-->
           <td><INPUT TYPE="submit" name="logon" value="Log in"></td>
          </tr>
         </table>
       </form>
      </td></tr>
     </table>

   
</body>
</html>

)=====";


