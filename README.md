<h1>Binary Class</h1>
<h3>Overview</h3>
A class which contains an std::string data member, and holds a binary value in it. (example: "10010011")<br>
The class can be initialized using decimal values (ints), or by string values, which all get converted and stripped into a binary value, which then gets assigned to the std::string data member.<br>

<h3>Usage</h3>

<h4>Initialization:</h4>
<p>Objects of Binary class type can be direct initialized with either decimal numbers or binary (string or char*) values: 
<p><i>Binary num1(16);<br>Binary num2("101001");</i></p>

<h4>Class Member Functions:</h4>
<p>Two member functions exist for the Binary class: getValue() and print().<br>
<i>getValue()</i> returns the object's binary value, <i>print()</i> outputs the binary value to the standard output, and returns an <i>std::ostream&</i> to allow such chaining of commands:</p>
<p><i>num1.print(std::cout) << std::endl;</i></p>

<h4>Non-member functions:</h4>
<p>The non-member functions are used for conversion between binary and decimal numbers.<br>
<i>binToDec()</i> converts a binary value to decimal, <i>decToBin()</i> decimal to binary.<br><br>
<i>binToDec()</i> takes either an std::string value, or a Binary object to do the conversion, returns an unsigned value.<br>
<i>decToBin()</i> takes an unsigned and returns an std::string.<br>
  
Examples:</p>
<p><i>decToBin(13);</i> //--> returns "1101"</p>

<i>std::string val = "1001";<br>
binToDec(val);</i> //--> returns 9</p>

<p><i>Binary num3("1110");<br>
binToDec(num3);</i> //--> returns 14</p>

<p>There is also a <i>powerOfNum()</i> function that raises a number to a power of another number to help with the binary to decimal conversions.</p>
