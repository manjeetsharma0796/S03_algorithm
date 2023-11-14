void fillSubset (vector<vector<int>>& subset, int arr[],int arrSize) {
        int arrIndx = 0;
        
        while(arrIndx < arrSize){
            int number = arr[arrIndx];
            int subsetSize = subset.size();

            for(int i = 0; i < subsetSize; i++) {
                subset.push_back(subset[i]);
                subset.back().push_back(number);
            }
            arrIndx += 1;
        }
    }
    
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        vector<vector<int>> subset = {{}};
        fillSubset(subset, arr, n);

        for(int i = 1; i < subset.size(); i++) {
            int sum = 0;

            for(int j = 0; j < subset[i].size(); j++) {
                sum += subset[i][j];
            }
            // cout<<endl<<sum<<endl;
            if(sum == 0) {
                return true;
            }
        }

        return false;
    }