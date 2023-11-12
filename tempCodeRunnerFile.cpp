struct Job {
    int profit;
    int deadline;
};

//Our comparator 
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}
