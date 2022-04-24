var database=firebase.database();

var ref=database.ref('questions');
var Qno=database.ref("display");
console.log(Qno);
var oa=document.querySelector("#option-a");
var ob=document.querySelector("#option-b");
var oc=document.querySelector("#option-c");
var od=document.querySelector("#option-d");
var s=document.querySelector("#question")
s.innerHTML="blah-blah";
var l="02";

ref.child("02").on('value',getdata,errdata);

function getdata(data)
{   
    console.log(data.val().q);
    var x=data.val()
    // q.value=x.q;
    // oa.value=x.a;
    // ob.value=x.b;
    // oc.value=x.c;
    // od.value=x.d;

}
function errdata(err)
{
    console.log(err);
}
