var c;c||(c=typeof Module !== 'undefined' ? Module : {});var k={},m;for(m in c)c.hasOwnProperty(m)&&(k[m]=c[m]);c.arguments=[];c.thisProgram="./this.program";c.quit=function(a,b){throw b;};c.preRun=[];c.postRun=[];var r=!1,u=!1,v=!1,aa=!1;r="object"===typeof window;u="function"===typeof importScripts;v="object"===typeof process&&"function"===typeof require&&!r&&!u;aa=!r&&!v&&!u;var w="";function ba(a){return c.locateFile?c.locateFile(a,w):w+a}
if(v){w=__dirname+"/";var ca,da;c.read=function(a,b){ca||(ca=require("fs"));da||(da=require("path"));a=da.normalize(a);a=ca.readFileSync(a);return b?a:a.toString()};c.readBinary=function(a){a=c.read(a,!0);a.buffer||(a=new Uint8Array(a));assert(a.buffer);return a};1<process.argv.length&&(c.thisProgram=process.argv[1].replace(/\\/g,"/"));c.arguments=process.argv.slice(2);"undefined"!==typeof module&&(module.exports=c);process.on("uncaughtException",function(a){if(!(a instanceof x))throw a;});process.on("unhandledRejection",
y);c.quit=function(a){process.exit(a)};c.inspect=function(){return"[Emscripten Module object]"}}else if(aa)"undefined"!=typeof read&&(c.read=function(a){return read(a)}),c.readBinary=function(a){if("function"===typeof readbuffer)return new Uint8Array(readbuffer(a));a=read(a,"binary");assert("object"===typeof a);return a},"undefined"!=typeof scriptArgs?c.arguments=scriptArgs:"undefined"!=typeof arguments&&(c.arguments=arguments),"function"===typeof quit&&(c.quit=function(a){quit(a)});else if(r||u)u?
w=self.location.href:document.currentScript&&(w=document.currentScript.src),w=0!==w.indexOf("blob:")?w.substr(0,w.lastIndexOf("/")+1):"",c.read=function(a){var b=new XMLHttpRequest;b.open("GET",a,!1);b.send(null);return b.responseText},u&&(c.readBinary=function(a){var b=new XMLHttpRequest;b.open("GET",a,!1);b.responseType="arraybuffer";b.send(null);return new Uint8Array(b.response)}),c.readAsync=function(a,b,d){var e=new XMLHttpRequest;e.open("GET",a,!0);e.responseType="arraybuffer";e.onload=function(){200==
e.status||0==e.status&&e.response?b(e.response):d()};e.onerror=d;e.send(null)},c.setWindowTitle=function(a){document.title=a};var ea=c.print||("undefined"!==typeof console?console.log.bind(console):"undefined"!==typeof print?print:null),z=c.printErr||("undefined"!==typeof printErr?printErr:"undefined"!==typeof console&&console.warn.bind(console)||ea);for(m in k)k.hasOwnProperty(m)&&(c[m]=k[m]);k=void 0;function fa(a){var b;b||(b=16);return Math.ceil(a/b)*b}
function ha(a){A||(A={});A[a]||(A[a]=1,z(a))}var A,ia={"f64-rem":function(a,b){return a%b},"debugger":function(){debugger}},B=!1;function assert(a,b){a||y("Assertion failed: "+b)}function ja(a){var b;if(0===b||!a)return"";for(var d=0,e,f=0;;){e=C[a+f>>0];d|=e;if(0==e&&!b)break;f++;if(b&&f==b)break}b||(b=f);e="";if(128>d){for(;0<b;)d=String.fromCharCode.apply(String,C.subarray(a,a+Math.min(b,1024))),e=e?e+d:d,a+=1024,b-=1024;return e}return ka(C,a)}
var la="undefined"!==typeof TextDecoder?new TextDecoder("utf8"):void 0;
function ka(a,b){for(var d=b;a[d];)++d;if(16<d-b&&a.subarray&&la)return la.decode(a.subarray(b,d));for(d="";;){var e=a[b++];if(!e)return d;if(e&128){var f=a[b++]&63;if(192==(e&224))d+=String.fromCharCode((e&31)<<6|f);else{var g=a[b++]&63;if(224==(e&240))e=(e&15)<<12|f<<6|g;else{var h=a[b++]&63;if(240==(e&248))e=(e&7)<<18|f<<12|g<<6|h;else{var n=a[b++]&63;if(248==(e&252))e=(e&3)<<24|f<<18|g<<12|h<<6|n;else{var l=a[b++]&63;e=(e&1)<<30|f<<24|g<<18|h<<12|n<<6|l}}}65536>e?d+=String.fromCharCode(e):(e-=
65536,d+=String.fromCharCode(55296|e>>10,56320|e&1023))}}else d+=String.fromCharCode(e)}}"undefined"!==typeof TextDecoder&&new TextDecoder("utf-16le");
function ma(a){for(var b=0,d=0;d<a.length;++d){var e=a.charCodeAt(d);55296<=e&&57343>=e&&(e=65536+((e&1023)<<10)|a.charCodeAt(++d)&1023);127>=e?++b:b=2047>=e?b+2:65535>=e?b+3:2097151>=e?b+4:67108863>=e?b+5:b+6}var f=b+1;b=na(f);d=b;e=oa;if(0<f){f=d+f-1;for(var g=0;g<a.length;++g){var h=a.charCodeAt(g);if(55296<=h&&57343>=h){var n=a.charCodeAt(++g);h=65536+((h&1023)<<10)|n&1023}if(127>=h){if(d>=f)break;e[d++]=h}else{if(2047>=h){if(d+1>=f)break;e[d++]=192|h>>6}else{if(65535>=h){if(d+2>=f)break;e[d++]=
224|h>>12}else{if(2097151>=h){if(d+3>=f)break;e[d++]=240|h>>18}else{if(67108863>=h){if(d+4>=f)break;e[d++]=248|h>>24}else{if(d+5>=f)break;e[d++]=252|h>>30;e[d++]=128|h>>24&63}e[d++]=128|h>>18&63}e[d++]=128|h>>12&63}e[d++]=128|h>>6&63}e[d++]=128|h&63}}e[d]=0}return b}var buffer,oa,C,D,pa;
function qa(){c.HEAP8=oa=new Int8Array(buffer);c.HEAP16=new Int16Array(buffer);c.HEAP32=D=new Int32Array(buffer);c.HEAPU8=C=new Uint8Array(buffer);c.HEAPU16=new Uint16Array(buffer);c.HEAPU32=pa=new Uint32Array(buffer);c.HEAPF32=new Float32Array(buffer);c.HEAPF64=new Float64Array(buffer)}var E,F,ra,G,sa,ta,H;E=F=ra=G=sa=ta=H=0;
function ua(){y("Cannot enlarge memory arrays. Either (1) compile with  -s TOTAL_MEMORY=X  with X higher than the current value "+I+", (2) compile with  -s ALLOW_MEMORY_GROWTH=1  which allows increasing the size at runtime, or (3) if you want malloc to return NULL (0) instead of this abort, compile with  -s ABORTING_MALLOC=0 ")}var va=c.TOTAL_STACK||5242880,I=c.TOTAL_MEMORY||16777216;I<va&&z("TOTAL_MEMORY should be larger than TOTAL_STACK, was "+I+"! (TOTAL_STACK="+va+")");
c.buffer?buffer=c.buffer:("object"===typeof WebAssembly&&"function"===typeof WebAssembly.Memory?(c.wasmMemory=new WebAssembly.Memory({initial:I/65536,maximum:I/65536}),buffer=c.wasmMemory.buffer):buffer=new ArrayBuffer(I),c.buffer=buffer);qa();function J(a){for(;0<a.length;){var b=a.shift();if("function"==typeof b)b();else{var d=b.j;"number"===typeof d?void 0===b.a?c.dynCall_v(d):c.dynCall_vi(d,b.a):d(void 0===b.a?null:b.a)}}}var wa=[],xa=[],ya=[],za=[],Aa=[],Ba=!1;
function Ca(){var a=c.preRun.shift();wa.unshift(a)}var K=0,Da=null,L=null;c.preloadedImages={};c.preloadedAudios={};function Ea(a){return String.prototype.startsWith?a.startsWith("data:application/octet-stream;base64,"):0===a.indexOf("data:application/octet-stream;base64,")}
(function(){function a(){try{if(c.wasmBinary)return new Uint8Array(c.wasmBinary);if(c.readBinary)return c.readBinary(f);throw"both async and sync fetching of the wasm failed";}catch(p){y(p)}}function b(){return c.wasmBinary||!r&&!u||"function"!==typeof fetch?new Promise(function(b){b(a())}):fetch(f,{credentials:"same-origin"}).then(function(a){if(!a.ok)throw"failed to load wasm binary file at '"+f+"'";return a.arrayBuffer()}).catch(function(){return a()})}function d(a){function d(a){n=a.exports;if(n.memory){a=
n.memory;var b=c.buffer;a.byteLength<b.byteLength&&z("the new buffer in mergeMemory is smaller than the previous one. in native wasm, we should grow memory here");b=new Int8Array(b);(new Int8Array(a)).set(b);c.buffer=buffer=a;qa()}c.asm=n;c.usingWasm=!0;K--;c.monitorRunDependencies&&c.monitorRunDependencies(K);0==K&&(null!==Da&&(clearInterval(Da),Da=null),L&&(a=L,L=null,a()))}function e(a){d(a.instance)}function g(a){b().then(function(a){return WebAssembly.instantiate(a,h)}).then(a,function(a){z("failed to asynchronously prepare wasm: "+
a);y(a)})}if("object"!==typeof WebAssembly)return z("no native wasm support detected"),!1;if(!(c.wasmMemory instanceof WebAssembly.Memory))return z("no native wasm Memory in use"),!1;a.memory=c.wasmMemory;h.global={NaN:NaN,Infinity:Infinity};h["global.Math"]=Math;h.env=a;K++;c.monitorRunDependencies&&c.monitorRunDependencies(K);if(c.instantiateWasm)try{return c.instantiateWasm(h,d)}catch(lb){return z("Module.instantiateWasm callback failed with error: "+lb),!1}c.wasmBinary||"function"!==typeof WebAssembly.instantiateStreaming||
Ea(f)||"function"!==typeof fetch?g(e):WebAssembly.instantiateStreaming(fetch(f,{credentials:"same-origin"}),h).then(e,function(a){z("wasm streaming compile failed: "+a);z("falling back to ArrayBuffer instantiation");g(e)});return{}}var e="hello_triangle.wast",f="hello_triangle.wasm",g="hello_triangle.temp.asm.js";Ea(e)||(e=ba(e));Ea(f)||(f=ba(f));Ea(g)||(g=ba(g));var h={global:null,env:null,asm2wasm:ia,parent:c},n=null;c.asmPreload=c.asm;var l=c.reallocBuffer;c.reallocBuffer=function(a){if("asmjs"===
t)var b=l(a);else a:{var d=c.usingWasm?65536:16777216;0<a%d&&(a+=d-a%d);d=c.buffer.byteLength;if(c.usingWasm)try{b=-1!==c.wasmMemory.grow((a-d)/65536)?c.buffer=c.wasmMemory.buffer:null;break a}catch(zb){b=null;break a}b=void 0}return b};var t="";c.asm=function(a,b){if(!b.table){a=c.wasmTableSize;void 0===a&&(a=1024);var e=c.wasmMaxTableSize;b.table="object"===typeof WebAssembly&&"function"===typeof WebAssembly.Table?void 0!==e?new WebAssembly.Table({initial:a,maximum:e,element:"anyfunc"}):new WebAssembly.Table({initial:a,
element:"anyfunc"}):Array(a);c.wasmTable=b.table}b.memoryBase||(b.memoryBase=c.STATIC_BASE);b.tableBase||(b.tableBase=0);b=d(b);assert(b,"no binaryen method succeeded.");return b}})();E=1024;F=E+5264;xa.push();c.STATIC_BASE=E;c.STATIC_BUMP=5264;F+=16;var Fa=[null,[],[]],M=0;function N(){M+=4;return D[M-4>>2]}var Ga={};function O(){y()}var Ha=0;
function Ia(a){return a?("number"==typeof a&&(a=ja(a)),"#window"==a?window:"#document"==a?document:"#screen"==a?window.screen:"#canvas"==a?c.canvas:"string"==typeof a?document.getElementById(a):a):window}var P=null,Q="",R=0,S=null,Ja=0,Ka=0,La=0,Ma=0,Na=[],Oa={},Pa,Qa,T,Ra=!1,Sa=!1,Ta=[];
function Ua(){function a(){Sa=document.pointerLockElement===c.canvas||document.mozPointerLockElement===c.canvas||document.webkitPointerLockElement===c.canvas||document.msPointerLockElement===c.canvas}c.preloadPlugins||(c.preloadPlugins=[]);if(!Va){Va=!0;try{U=!0}catch(d){U=!1,console.log("warning: no blob constructor, cannot create blobs with mimetypes")}Wa="undefined"!=typeof MozBlobBuilder?MozBlobBuilder:"undefined"!=typeof WebKitBlobBuilder?WebKitBlobBuilder:U?null:console.log("warning: no BlobBuilder");
V="undefined"!=typeof window?window.URL?window.URL:window.webkitURL:void 0;c.g||"undefined"!==typeof V||(console.log("warning: Browser does not support creating object URLs. Built-in browser image decoding will not be available."),c.g=!0);c.preloadPlugins.push({canHandle:function(a){return!c.g&&/\.(jpg|jpeg|png|bmp)$/i.test(a)},handle:function(a,b,f,g){var d=null;if(U)try{d=new Blob([a],{type:Xa(b)}),d.size!==a.length&&(d=new Blob([(new Uint8Array(a)).buffer],{type:Xa(b)}))}catch(t){ha("Blob constructor present but fails: "+
t+"; falling back to blob builder")}d||(d=new Wa,d.append((new Uint8Array(a)).buffer),d=d.getBlob());var e=V.createObjectURL(d),l=new Image;l.onload=function(){assert(l.complete,"Image "+b+" could not be decoded");var d=document.createElement("canvas");d.width=l.width;d.height=l.height;d.getContext("2d").drawImage(l,0,0);c.preloadedImages[b]=d;V.revokeObjectURL(e);f&&f(a)};l.onerror=function(){console.log("Image "+e+" could not be decoded");g&&g()};l.src=e}});c.preloadPlugins.push({canHandle:function(a){return!c.F&&
a.substr(-4)in{".ogg":1,".wav":1,".mp3":1}},handle:function(a,b,f,g){function d(d){l||(l=!0,c.preloadedAudios[b]=d,f&&f(a))}function e(){l||(l=!0,c.preloadedAudios[b]=new Audio,g&&g())}var l=!1;if(U){try{var t=new Blob([a],{type:Xa(b)})}catch(q){return e()}t=V.createObjectURL(t);var p=new Audio;p.addEventListener("canplaythrough",function(){d(p)},!1);p.onerror=function(){if(!l){console.log("warning: browser could not fully decode audio "+b+", trying slower base64 approach");for(var e="",f=0,h=0,g=
0;g<a.length;g++)for(f=f<<8|a[g],h+=8;6<=h;){var n=f>>h-6&63;h-=6;e+="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[n]}2==h?(e+="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(f&3)<<4],e+="=="):4==h&&(e+="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(f&15)<<2],e+="=");p.src="data:audio/x-"+b.substr(-3)+";base64,"+e;d(p)}};p.src=t;Ya(function(){d(p)})}else return e()}});var b=c.canvas;b&&(b.requestPointerLock=b.requestPointerLock||b.mozRequestPointerLock||
b.webkitRequestPointerLock||b.msRequestPointerLock||function(){},b.exitPointerLock=document.exitPointerLock||document.mozExitPointerLock||document.webkitExitPointerLock||document.msExitPointerLock||function(){},b.exitPointerLock=b.exitPointerLock.bind(document),document.addEventListener("pointerlockchange",a,!1),document.addEventListener("mozpointerlockchange",a,!1),document.addEventListener("webkitpointerlockchange",a,!1),document.addEventListener("mspointerlockchange",a,!1),c.elementPointerLock&&
b.addEventListener("click",function(a){!Sa&&c.canvas.requestPointerLock&&(c.canvas.requestPointerLock(),a.preventDefault())},!1))}}
function Za(a,b,d,e){if(b&&c.b&&a==c.canvas)return c.b;if(b){var f={antialias:!1,alpha:!1};if(e)for(var g in e)f[g]=e[g];if(f=$a(a,f))var h=ab[f].GLctx}else h=a.getContext("2d");if(!h)return null;d&&(b||assert("undefined"===typeof GLctx,"cannot set in module if GLctx is used, but we are a non-GL context that would replace it"),c.b=h,b&&bb(f),c.G=b,Ta.forEach(function(a){a()}),Ua());return h}var cb=!1,db=void 0,W=void 0;
function eb(a,b,d){function e(){Ra=!1;var a=f.parentNode;(document.fullscreenElement||document.mozFullScreenElement||document.msFullscreenElement||document.webkitFullscreenElement||document.webkitCurrentFullScreenElement)===a?(f.exitFullscreen=document.exitFullscreen||document.cancelFullScreen||document.mozCancelFullScreen||document.msExitFullscreen||document.webkitCancelFullScreen||function(){},f.exitFullscreen=f.exitFullscreen.bind(document),db&&f.requestPointerLock(),Ra=!0,W?("undefined"!=typeof SDL&&
(D[SDL.screen>>2]=pa[SDL.screen>>2]|8388608),X(c.canvas),fb()):X(f)):(a.parentNode.insertBefore(f,a),a.parentNode.removeChild(a),W?("undefined"!=typeof SDL&&(D[SDL.screen>>2]=pa[SDL.screen>>2]&-8388609),X(c.canvas),fb()):X(f));if(c.onFullScreen)c.onFullScreen(Ra);if(c.onFullscreen)c.onFullscreen(Ra)}db=a;W=b;gb=d;"undefined"===typeof db&&(db=!0);"undefined"===typeof W&&(W=!1);"undefined"===typeof gb&&(gb=null);var f=c.canvas;cb||(cb=!0,document.addEventListener("fullscreenchange",e,!1),document.addEventListener("mozfullscreenchange",
e,!1),document.addEventListener("webkitfullscreenchange",e,!1),document.addEventListener("MSFullscreenChange",e,!1));var g=document.createElement("div");f.parentNode.insertBefore(g,f);g.appendChild(f);g.requestFullscreen=g.requestFullscreen||g.mozRequestFullScreen||g.msRequestFullscreen||(g.webkitRequestFullscreen?function(){g.webkitRequestFullscreen(Element.ALLOW_KEYBOARD_INPUT)}:null)||(g.webkitRequestFullScreen?function(){g.webkitRequestFullScreen(Element.ALLOW_KEYBOARD_INPUT)}:null);d?g.requestFullscreen({H:d}):
g.requestFullscreen()}function hb(a,b,d){z("Browser.requestFullScreen() is deprecated. Please call Browser.requestFullscreen instead.");hb=function(a,b,d){return eb(a,b,d)};return eb(a,b,d)}var Y=0;function ib(a){var b=Date.now();if(0===Y)Y=b+1E3/60;else for(;b+2>=Y;)Y+=1E3/60;setTimeout(a,Math.max(Y-b,0))}
function jb(a){"undefined"===typeof window?ib(a):(window.requestAnimationFrame||(window.requestAnimationFrame=window.requestAnimationFrame||window.mozRequestAnimationFrame||window.webkitRequestAnimationFrame||window.msRequestAnimationFrame||window.oRequestAnimationFrame||ib),window.requestAnimationFrame(a))}function Ya(a){c.noExitRuntime=!0;setTimeout(function(){B||a()},1E4)}
function Xa(a){return{jpg:"image/jpeg",jpeg:"image/jpeg",png:"image/png",bmp:"image/bmp",ogg:"audio/ogg",wav:"audio/wav",mp3:"audio/mpeg"}[a.substr(a.lastIndexOf(".")+1)]}var kb=[];function fb(){var a=c.canvas;kb.forEach(function(b){b(a.width,a.height)})}
function X(a,b,d){b&&d?(a.v=b,a.o=d):(b=a.v,d=a.o);var e=b,f=d;c.forcedAspectRatio&&0<c.forcedAspectRatio&&(e/f<c.forcedAspectRatio?e=Math.round(f*c.forcedAspectRatio):f=Math.round(e/c.forcedAspectRatio));if((document.fullscreenElement||document.mozFullScreenElement||document.msFullscreenElement||document.webkitFullscreenElement||document.webkitCurrentFullScreenElement)===a.parentNode&&"undefined"!=typeof screen){var g=Math.min(screen.width/e,screen.height/f);e=Math.round(e*g);f=Math.round(f*g)}W?
(a.width!=e&&(a.width=e),a.height!=f&&(a.height=f),"undefined"!=typeof a.style&&(a.style.removeProperty("width"),a.style.removeProperty("height"))):(a.width!=b&&(a.width=b),a.height!=d&&(a.height=d),"undefined"!=typeof a.style&&(e!=b||f!=d?(a.style.setProperty("width",e+"px","important"),a.style.setProperty("height",f+"px","important")):(a.style.removeProperty("width"),a.style.removeProperty("height"))))}var Va,U,Wa,V,gb;
function mb(a,b){Ka=a;La=b;if(S)if(0==a)P=function(){var a=Math.max(0,Qa+b-O())|0;setTimeout(T,a)},Q="timeout";else if(1==a)P=function(){jb(T)},Q="rAF";else if(2==a){if("undefined"===typeof setImmediate){var d=[];addEventListener("message",function(a){if("setimmediate"===a.data||"setimmediate"===a.data.target)a.stopPropagation(),d.shift()()},!0);setImmediate=function(a){d.push(a);u?(void 0===c.setImmediates&&(c.setImmediates=[]),c.setImmediates.push(a),postMessage({target:"setimmediate"})):postMessage("setimmediate",
"*")}}P=function(){setImmediate(T)};Q="immediate"}}
function nb(a,b,d,e,f){c.noExitRuntime=!0;assert(!S,"emscripten_set_main_loop: there can only be one main loop function at once: call emscripten_cancel_main_loop to cancel the previous one before setting a new one with different parameters.");S=a;Ja=e;var g="undefined"!==typeof e?function(){c.dynCall_vi(a,e)}:function(){c.dynCall_v(a)};var h=R;T=function(){if(!B)if(0<Na.length){var a=Date.now(),b=Na.shift();b.j(b.a);if(Pa){var d=Pa,e=0==d%1?d-1:Math.floor(d);Pa=b.A?e:(8*d+(e+.5))/9}console.log('main loop blocker "'+
b.name+'" took '+(Date.now()-a)+" ms");c.setStatus&&(a=c.statusMessage||"Please wait...",b=Pa,d=Oa.C,b?b<d?c.setStatus(a+" ("+(d-b)+"/"+d+")"):c.setStatus(a):c.setStatus(""));h<R||setTimeout(T,0)}else if(!(h<R))if(Ma=Ma+1|0,1==Ka&&1<La&&0!=Ma%La)P();else{0==Ka&&(Qa=O());"timeout"===Q&&c.b&&(z("Looks like you are rendering without using requestAnimationFrame for the main loop. You should use 0 for the frame rate in emscripten_set_main_loop in order to use requestAnimationFrame, as that can greatly improve your frame rates!"),
Q="");a:if(!(B||c.preMainLoop&&!1===c.preMainLoop())){try{g()}catch(q){if(q instanceof x)break a;q&&"object"===typeof q&&q.stack&&z("exception thrown: "+[q,q.stack]);throw q;}c.postMainLoop&&c.postMainLoop()}h<R||("object"===typeof SDL&&SDL.audio&&SDL.audio.u&&SDL.audio.u(),P())}};f||(b&&0<b?mb(0,1E3/b):mb(1,1),P());if(d)throw"SimulateInfiniteLoop";}var ob=1,ab=[],pb=null,qb={},rb=[];
function $a(a,b){function d(){}"undefined"===typeof b.majorVersion&&"undefined"===typeof b.minorVersion&&(b.majorVersion=1,b.minorVersion=0);try{a.addEventListener("webglcontextcreationerror",d,!1);try{if(1==b.majorVersion&&0==b.minorVersion)var e=a.getContext("webgl",b)||a.getContext("experimental-webgl",b);else if(2==b.majorVersion&&0==b.minorVersion)e=a.getContext("webgl2",b);else throw"Unsupported WebGL context version "+majorVersion+"."+minorVersion+"!";}finally{a.removeEventListener("webglcontextcreationerror",
d,!1)}if(!e)throw":(";}catch(f){return 0}return e?sb(e,b):0}function sb(a,b){for(var d=ab,e=ob++,f=d.length;f<e;f++)d[f]=null;d={handle:e,attributes:b,version:b.majorVersion,GLctx:a};a.canvas&&(a.canvas.w=d);ab[e]=d;("undefined"===typeof b.enableExtensionsByDefault||b.enableExtensionsByDefault)&&tb(d);return e}function bb(a){a=ab[a];if(!a)return!1;GLctx=c.b=a.GLctx;pb=a;return!0}
function tb(a){a||(a=pb);if(!a.s){a.s=!0;var b=a.GLctx;if(2>a.version){var d=b.getExtension("ANGLE_instanced_arrays");d&&(b.vertexAttribDivisor=function(a,b){d.vertexAttribDivisorANGLE(a,b)},b.drawArraysInstanced=function(a,b,e,f){d.drawArraysInstancedANGLE(a,b,e,f)},b.drawElementsInstanced=function(a,b,e,f,g){d.drawElementsInstancedANGLE(a,b,e,f,g)});var e=b.getExtension("OES_vertex_array_object");e&&(b.createVertexArray=function(){return e.createVertexArrayOES()},b.deleteVertexArray=function(a){e.deleteVertexArrayOES(a)},
b.bindVertexArray=function(a){e.bindVertexArrayOES(a)},b.isVertexArray=function(a){return e.isVertexArrayOES(a)});var f=b.getExtension("WEBGL_draw_buffers");f&&(b.drawBuffers=function(a,b){f.drawBuffersWEBGL(a,b)})}b.B=b.getExtension("EXT_disjoint_timer_query");var g="OES_texture_float OES_texture_half_float OES_standard_derivatives OES_vertex_array_object WEBGL_compressed_texture_s3tc WEBGL_depth_texture OES_element_index_uint EXT_texture_filter_anisotropic EXT_frag_depth WEBGL_draw_buffers ANGLE_instanced_arrays OES_texture_float_linear OES_texture_half_float_linear EXT_blend_minmax EXT_shader_texture_lod WEBGL_compressed_texture_pvrtc EXT_color_buffer_half_float WEBGL_color_buffer_float EXT_sRGB WEBGL_compressed_texture_etc1 EXT_disjoint_timer_query WEBGL_compressed_texture_etc WEBGL_compressed_texture_astc EXT_color_buffer_float WEBGL_compressed_texture_s3tc_srgb EXT_disjoint_timer_query_webgl2".split(" ");
(a=b.getSupportedExtensions())&&0<a.length&&b.getSupportedExtensions().forEach(function(a){-1!=g.indexOf(a)&&b.getExtension(a)})}}v?O=function(){var a=process.hrtime();return 1E3*a[0]+a[1]/1E6}:"undefined"!==typeof dateNow?O=dateNow:"object"===typeof self&&self.performance&&"function"===typeof self.performance.now?O=function(){return self.performance.now()}:"object"===typeof performance&&"function"===typeof performance.now?O=function(){return performance.now()}:O=Date.now;
(function(){if("undefined"!==typeof window){window.addEventListener("gamepadconnected",function(){++Ha});window.addEventListener("gamepaddisconnected",function(){--Ha});var a=navigator.getGamepads?navigator.getGamepads():navigator.webkitGetGamepads?navigator.webkitGetGamepads():null;a&&(Ha=a.length)}})();c.requestFullScreen=function(a,b,d){z("Module.requestFullScreen is deprecated. Please call Module.requestFullscreen instead.");c.requestFullScreen=c.requestFullscreen;hb(a,b,d)};
c.requestFullscreen=function(a,b,d){eb(a,b,d)};c.requestAnimationFrame=function(a){jb(a)};c.setCanvasSize=function(a,b,d){X(c.canvas,a,b);d||fb()};c.pauseMainLoop=function(){P=null;R++};c.resumeMainLoop=function(){R++;var a=Ka,b=La,d=S;S=null;nb(d,0,!1,Ja,!0);mb(a,b);P()};c.getUserMedia=function(){window.getUserMedia||(window.getUserMedia=navigator.getUserMedia||navigator.mozGetUserMedia);window.getUserMedia(void 0)};c.createContext=function(a,b,d,e){return Za(a,b,d,e)};
for(var GLctx,Z=0;256>Z;Z++);for(Z=0;32>Z;Z++)rb.push(Array(Z));var ub=F;F=F+4+15&-16;H=ub;ra=G=fa(F);sa=ra+va;ta=fa(sa);D[H>>2]=ta;c.wasmTableSize=8;c.wasmMaxTableSize=8;c.h={};
c.i={abort:y,enlargeMemory:function(){ua()},getTotalMemory:function(){return I},abortOnCannotGrowMemory:ua,___setErrNo:function(a){c.___errno_location&&(D[c.___errno_location()>>2]=a);return a},___syscall140:function(a,b){M=b;try{var d=Ga.l();N();var e=N(),f=N(),g=N();FS.D(d,e,g);D[f>>2]=d.position;d.m&&0===e&&0===g&&(d.m=null);return 0}catch(h){return"undefined"!==typeof FS&&h instanceof FS.c||y(h),-h.f}},___syscall146:function(a,b){M=b;try{var d=N(),e=N(),f=N();for(b=a=0;b<f;b++){for(var g=D[e+
8*b>>2],h=D[e+(8*b+4)>>2],n=0;n<h;n++){var l=d,t=C[g+n],p=Fa[l];assert(p);0===t||10===t?((1===l?ea:z)(ka(p,0)),p.length=0):p.push(t)}a+=h}return a}catch(q){return"undefined"!==typeof FS&&q instanceof FS.c||y(q),-q.f}},___syscall54:function(a,b){M=b;return 0},___syscall6:function(a,b){M=b;try{var d=Ga.l();FS.close(d);return 0}catch(e){return"undefined"!==typeof FS&&e instanceof FS.c||y(e),-e.f}},_emscripten_get_now:O,_emscripten_memcpy_big:function(a,b,d){C.set(C.subarray(b,b+d),a);return a},_emscripten_set_canvas_element_size:function(a,
b,d){a=a?Ia(a):c.canvas;if(!a)return-4;a.width=b;a.height=d;return 0},_emscripten_set_main_loop:nb,_emscripten_webgl_create_context:function(a,b){var d={};d.alpha=!!D[b>>2];d.depth=!!D[b+4>>2];d.stencil=!!D[b+8>>2];d.antialias=!!D[b+12>>2];d.premultipliedAlpha=!!D[b+16>>2];d.preserveDrawingBuffer=!!D[b+20>>2];d.preferLowPowerToHighPerformance=!!D[b+24>>2];d.failIfMajorPerformanceCaveat=!!D[b+28>>2];d.majorVersion=D[b+32>>2];d.minorVersion=D[b+36>>2];d.enableExtensionsByDefault=D[b+40>>2];d.explicitSwapControl=
D[b+44>>2];d.renderViaOffscreenBackBuffer=D[b+48>>2];a=(a=ja(a))&&"#canvas"!==a||!c.canvas?qb[a]||Ia(a):c.canvas.id?qb[c.canvas.id]||Ia(c.canvas.id):c.canvas;return!a||d.explicitSwapControl?0:$a(a,d)},_emscripten_webgl_init_context_attributes:function(a){D[a>>2]=1;D[a+4>>2]=1;D[a+8>>2]=0;D[a+12>>2]=1;D[a+16>>2]=1;D[a+20>>2]=0;D[a+24>>2]=0;D[a+28>>2]=0;D[a+32>>2]=1;D[a+36>>2]=0;D[a+40>>2]=1;D[a+44>>2]=0;D[a+48>>2]=0},_emscripten_webgl_make_context_current:function(a){return bb(a)?0:-5},_glClear:function(a){GLctx.clear(a)},
_glClearColor:function(a,b,d,e){GLctx.clearColor(a,b,d,e)},DYNAMICTOP_PTR:H,STACKTOP:G};var vb=c.asm(c.h,c.i,buffer);c.asm=vb;c.___errno_location=function(){return c.asm.___errno_location.apply(null,arguments)};c._main=function(){return c.asm._main.apply(null,arguments)};c._malloc=function(){return c.asm._malloc.apply(null,arguments)};var na=c.stackAlloc=function(){return c.asm.stackAlloc.apply(null,arguments)};c.dynCall_iiii=function(){return c.asm.dynCall_iiii.apply(null,arguments)};
c.dynCall_v=function(){return c.asm.dynCall_v.apply(null,arguments)};c.asm=vb;function x(a){this.name="ExitStatus";this.message="Program terminated with exit("+a+")";this.status=a}x.prototype=Error();x.prototype.constructor=x;L=function wb(){c.calledRun||xb();c.calledRun||(L=wb)};
c.callMain=function(a){a=a||[];Ba||(Ba=!0,J(xa));var b=a.length+1,d=na(4*(b+1));D[d>>2]=ma(c.thisProgram);for(var e=1;e<b;e++)D[(d>>2)+e]=ma(a[e-1]);D[(d>>2)+b]=0;try{var f=c._main(b,d,0);if(!c.noExitRuntime||0!==f){if(!c.noExitRuntime&&(B=!0,G=void 0,J(za),c.onExit))c.onExit(f);c.quit(f,new x(f))}}catch(g){g instanceof x||("SimulateInfiniteLoop"==g?c.noExitRuntime=!0:((a=g)&&"object"===typeof g&&g.stack&&(a=[g,g.stack]),z("exception thrown: "+a),c.quit(1,g)))}finally{}};
function xb(a){function b(){if(!c.calledRun&&(c.calledRun=!0,!B)){Ba||(Ba=!0,J(xa));J(ya);if(c.onRuntimeInitialized)c.onRuntimeInitialized();c._main&&yb&&c.callMain(a);if(c.postRun)for("function"==typeof c.postRun&&(c.postRun=[c.postRun]);c.postRun.length;){var b=c.postRun.shift();Aa.unshift(b)}J(Aa)}}a=a||c.arguments;if(!(0<K)){if(c.preRun)for("function"==typeof c.preRun&&(c.preRun=[c.preRun]);c.preRun.length;)Ca();J(wa);0<K||c.calledRun||(c.setStatus?(c.setStatus("Running..."),setTimeout(function(){setTimeout(function(){c.setStatus("")},
1);b()},1)):b())}}c.run=xb;function y(a){if(c.onAbort)c.onAbort(a);void 0!==a?(ea(a),z(a),a=JSON.stringify(a)):a="";B=!0;throw"abort("+a+"). Build with -s ASSERTIONS=1 for more info.";}c.abort=y;if(c.preInit)for("function"==typeof c.preInit&&(c.preInit=[c.preInit]);0<c.preInit.length;)c.preInit.pop()();var yb=!0;c.noInitialRun&&(yb=!1);c.noExitRuntime=!0;xb();