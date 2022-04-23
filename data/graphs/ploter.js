const fs = require('fs');
const { USERNAME, API_KEY } = require('../../config.json');
var plotly = require('plotly')(USERNAME, API_KEY);
const TAM = 6;
const N = ["n-10", "n-100", "n-1K", "n-10K", "n-100K", "n-1M"];

var insertionData = [];
var mergeData = [];
var radixData = [];

for(i = 1; i <= TAM; i++){
    try {
        var pow = 10**i;
        insertionData.push(fs.readFileSync(`../output/n${pow}/InsertionSort.out`, 'utf8'));
        mergeData.push(fs.readFileSync(`../output/n${pow}/MergeSort.out`, 'utf8'));
        radixData.push(fs.readFileSync(`../output/n${pow}/RadixSort.out`, 'utf8'));
    
    } catch (err) {
      console.error(err);
    }
}

for(i = 1; i <= TAM; i++){
    insertionData[i-1] = parseFloat(insertionData[i-1].split('Tempo medio: ')[1]);
    mergeData[i-1] = parseFloat(mergeData[i-1].split('Tempo medio: ')[1]);
    radixData[i-1] = parseFloat(radixData[i-1].split('Tempo medio: ')[1]);
}

// INSERTION SORT
var insertion = {
    x: N,
    y: insertionData,
    type: 'scatter'
};

var layoutInsertion = {
    title: "InsertionSort",
    fileopt : "overwrite", 
    filename : "insertionGraph",
    xaxis: {
        title: {
            text: "Instancia",
            standoff: 20
        }
    },
    yaxis: {
        title: {
            text: "Tempo",
            standoff: 40
        }
    }
};

var insertionGraph = [insertion];

var graphOptions = {layout: layoutInsertion, filename: "insertionGraph", fileopt: "overwrite"};
plotly.plot(insertionGraph, graphOptions, (err, msg) => {
    if (err) return console.log(err);
    console.log("Plot URL: " + msg.url);
});

//MERGE SORT
var merge = {
    x: N,
    y: mergeData,
    type: 'scatter'
};

var layoutMerge = {
    title: "MergeSort",
    fileopt : "overwrite", 
    filename : "mergeGraph",
    xaxis: {
        title: {
            text: "Instancia",
            standoff: 20
        }
    },
    yaxis: {
        title: {
            text: "Tempo",
            standoff: 40
        }
    }
};

var mergeGraph = [merge];

var graphOptions = {layout: layoutMerge, filename: "mergeGraph", fileopt: "overwrite"};
plotly.plot(mergeGraph, graphOptions, (err, msg) => {
    if (err) return console.log(err);
    console.log("Plot URL: " + msg.url);
});

// RADIX SORT
var radix = {
    x: N,
    y: radixData,
    type: 'scatter'
};

var layoutRadix = {
    title: "RadixSort",
    fileopt : "overwrite", 
    filename : "radixGraph",
    xaxis: {
        title: {
            text: "Instancia",
            standoff: 20
        }
    },
    yaxis: {
        title: {
            text: "Tempo",
            standoff: 40
        }
    }
};

var radixGraph = [radix];

var graphOptions = {layout: layoutRadix, filename: "radixGraph", fileopt: "overwrite"};
plotly.plot(radixGraph, graphOptions, (err, msg) => {
    if (err) return console.log(err);
    console.log("Plot URL: " + msg.url);
});

// COMPARACAO GERAL
var layoutGeral = {
    title: "Comparação",
    fileopt : "overwrite", 
    filename : "comparisonGraph",
    xaxis: {
        title: {
            text: "Instancia",
            standoff: 20
        }
    },
    yaxis: {
        title: {
            text: "Tempo",
            standoff: 40
        }
    }
};

insertion.name = "InsertionSort";
merge.name = "MergeSort";
radix.name = "RadixSort";

var comparisonGraph = [insertion, merge, radix];

var graphOptions = {layout: layoutGeral, filename: "comparisonGraph", fileopt: "overwrite"};
plotly.plot(comparisonGraph, graphOptions, (err, msg) => {
	if (err) return console.log(err);
	console.log("Plot URL: " + msg.url);
});

// MERGE X RADIX
var layout_merge_radix = {
    title: "Merge vs Radix",
    fileopt : "overwrite", 
    filename : "merge_radix_Graph",
    xaxis: {
        title: {
            text: "Instancia",
            standoff: 20
        }
    },
    yaxis: {
        title: {
            text: "Tempo",
            standoff: 40
        }
    }
};

var merge_radix_Graph = [merge, radix];

var graphOptions = {layout: layout_merge_radix, filename: "merge_radix_Graph", fileopt: "overwrite"};
plotly.plot(merge_radix_Graph, graphOptions, (err, msg) => {
	if (err) return console.log(err);
	console.log("Plot URL: " + msg.url);
});

// INSERTION X RADIX
var layout_insertion_radix = {
    title: "Insertion vs Radix",
    fileopt : "overwrite", 
    filename : "insertion_radix_Graph",
    xaxis: {
        title: {
            text: "Instancia",
            standoff: 20
        }
    },
    yaxis: {
        title: {
            text: "Tempo",
            standoff: 40
        }
    }
};

var insertion_radix_Graph = [insertion, radix];

var graphOptions = {layout: layout_insertion_radix, filename: "insertion_radix_Graph", fileopt: "overwrite"};
plotly.plot(insertion_radix_Graph, graphOptions, (err, msg) => {
	if (err) return console.log(err);
	console.log("Plot URL: " + msg.url);
});

// INSERTION X Merge
var layout_insertion_merge = {
    title: "Insertion vs merge",
    fileopt : "overwrite", 
    filename : "insertion_merge_Graph",
    xaxis: {
        title: {
            text: "Instancia",
            standoff: 20
        }
    },
    yaxis: {
        title: {
            text: "Tempo",
            standoff: 40
        }
    }
};

var insertion_merge_Graph = [insertion, merge];

var graphOptions = {layout: layout_insertion_merge, filename: "insertion_merge_Graph", fileopt: "overwrite"};
plotly.plot(insertion_merge_Graph, graphOptions, (err, msg) => {
	if (err) return console.log(err);
	console.log("Plot URL: " + msg.url);
});