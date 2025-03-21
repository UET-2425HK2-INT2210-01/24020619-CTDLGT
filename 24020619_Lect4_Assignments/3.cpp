/*
hash function			Chaning			         Linear Probing	
i	i+3	mod 17		    Key	Values	        	   Key	Values
1	4	4		        0	empty		            0	empty
3	6	6		        1	empty		            1	empty
18	21	4		        2	16		                2	16
8	11	11		        3	empty		            3	empty
23	26	9		        4	1->18->35		        4	1
35	38	4		        5	36		                5	18
11	14	14		        6	20		                6	35
36	39	5		        7	empty		            7	36
20	23	6		        8	empty		            8	20
16	19	2		        9	23		                9	23
				        10	empty		            10	empty
				        11	8		                11	8
				        12	empty		            12	empty
				        13	empty		            13	empty
				        14	11		                14	11
				        15	empty		            15	empty
				        16	empty		            16	empty
				        17	empty		            17	empty
*/