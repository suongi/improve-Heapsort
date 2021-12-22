## Efficiency has been increased by at least 15%
The code std.c come form network, may I take it as the standard code of Heapsort?  
After **swap(&arr[0], &arr[i])**, the tail-element go a long distance with exchange.  
In the code imp.c, the tail-element should be go a short distance with a high-  
probability. Using assignment statement instead the exchanging, so it's businesslike  
--though it hasn't a nice watching.  
Run the code test_std.c and test_imp.c to compare it.