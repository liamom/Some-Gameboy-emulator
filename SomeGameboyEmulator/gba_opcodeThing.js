String.prototype.hashCode = function() {
    var hash = 0, i, chr, len;
    if (this.length == 0) return hash;
    for (i = 0, len = this.length; i < len; i++) {
        chr   = this.charCodeAt(i);
        hash  = ((hash << 5) - hash) + chr;
        hash |= 0; // Convert to 32bit integer
    }
    return hash;
};

var rows = document.querySelectorAll('.withborder tr')
var columns = rows[0].children
var outObj = [];
var output = "";

for(var i = 1 ; i < 17/*rows.length*/ ; i++)
{
    var elms = rows[i].children;
    var first4 = elms[0].firstChild.textContent.replace(/ /g,'').replace('x','')

    for(var j = 1; j < elms.length ; j++){
        var second4 = columns[j].firstChild.textContent.replace(/ /g,'').replace('x','')
        var elmContense = elms[j].innerHTML.split("<br>")
        if(elmContense != "&nbsp;"){
            var name = elmContense[0].replace(/ /g,'_').replace(/ | |\-/g,'_').replace(/,/g,'_').replace('+','_').replace(/\(|\)/g,'_')
            var fullName = elmContense[0]
            var type = fullName.split(' ')[0];
            var cycles = elmContense[1].replace(/&nbsp;/g,' ')
            var registers = elmContense[2]
            var color = elms[j].getAttribute('bgcolor');

            //output += name + " = " + "0x" + first4 + second4 + ",/*" + fullName + " cycles: " + cycles + " registers: " + registers + "*/"
            //code+= name + " = " + "0x" + first4 + second4 + ","
            var comment = fullName + " cycles: " + cycles + " registers: " + registers
            outObj.push({
                code: "0x" + first4 + second4,
                type: type, 
                name: name,
                comment: comment , 
                fullName:fullName,
                cycles:cycles,
                registers,registers,
                color:color
            });
        }
    }

    output += code + "\n//" + comment + '\n'
}

outObj.sort(function(a,b){
    return a['type'].hashCode() - b['type'].hashCode()
})

var jumps_calls = outObj.filter(function(elm){
    return elm.color == '#ffcc99';
})
var load_store_move_8bit = outObj.filter(function(elm){
    return elm.color == '#ccccff';
})
var load_store_move_16bit = outObj.filter(function(elm){
    return elm.color == '#ccffcc';
})

var arithmetic_logical_8bit = outObj.filter(function(elm){
    return elm.color == '#ffff99';
})
var arithmetic_logical_16bit = outObj.filter(function(elm){
    return elm.color == '#ffcccc';
})
var rotations_shifts_8bit = outObj.filter(function(elm){
    return elm.color == '#80ffff';
})

function printArray(array){
    array.sort(function(a,b){
        return a['type'].hashCode() - b['type'].hashCode()
    })

    var out = "";
    array.forEach(function(e){
        out += e.name + " = " + e.code + ",//" + e.comment + "\n";

    });

    console.log(out);
}

printArray(rotations_shifts_8bit);