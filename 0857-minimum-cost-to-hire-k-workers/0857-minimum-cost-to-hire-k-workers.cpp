class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> wqRatio;

        // dekho ab ham nikalenge wage/quality ratio
        // 1. pehli baat aakhir ye ratio kyu ?????
        // thik hai aise sochate hai
        // hamre pass two opr the ki
        // 1. ki minimum utna wage to mile hi unhe
        // 2. ratio ban rhe wage/quality ka 


        // achcha ek maths ki eqution likh deta hu dhyan dena
        // top wali image pe jaao ab...

        // basically jo bhi K worker choose krenge ham unka ye ratio
        // same hona chaiye

        // ab wage/quality hi kyu clear huaa n
        // bas vhi store kr rhe 


        // 2. Doubt why pair, hme to ratio chaiye n bas
        // aage samjh jaoge...🤷‍♂️
        

        int n=quality.size();
        for(int i=0;i<n;i++){
            double Ration = static_cast<double>(wage[i]) / quality[i];
            // mai ratio ke sath quality bhi push kar rha hu esiliye
            // pair tha

            // why quality ???? 🤷‍♂️🤷‍♂️
            // aage samjh jaoge
            wqRatio.push_back({Ration,quality[i]});
        }

        sort(wqRatio.begin(),wqRatio.end());

        // sort esliye kiya kyuki mai chahta hu ki
        // jo smallest wage/quality ka ratio hai vo aage aa jaye
        // yani increasing order me
        // esiliye kiya


        // summary time itne portion ka

        // abhi tak hamne samjha ki wage/queality ka matlab bole
        // 1 unit quality ki value ki importance
        // hamne sikha store krna aur sort karna


        priority_queue<int> pq;


        // why PQ? abhi bhai, dekho bhai hame K worker chaiye n
        // to mai K worker rakhunga aur jab bhi k worder se zyada honge
        // tabhi mai ek worker ko pop karunga and ek ko add krunga
        // to akhir kise pop kru ?
        // jiski quality zyada hogi, use hi n
        // aur vo max PQ ke top me hoga

        // ye baat bas read kr lo loop me samjh aa jayegi baat
        // trust me, @abhirai1 is here, crystal clear kar dunga concepts

        // bas patience bna ke rakho

        double ans=numeric_limits<double>::max();

        // ye ans hai jisme minimum answer store krte hai ham log
        // yani ki int ka jo INT_MAX hota hai, vaise hi double me aise likhate hai
        // sach batau aaj mujhe bhi ye syntax dekhna pada ki kaise krte hai declare

        int currentQuality=0;
        // ye variable aage samjh aayega


        // ⚡⚡⚡ Most Important part 

        // abhi hamare pass ek array hai jisme wage/quality ka ratio hai
        // quality ke sath, pair me

        // concept dekho...
        // ham hmesha value ko PQ me push karenge and currQuality ka sum
        // nikalenge, currQuality ye bta rha hoga ki, jo K worker ka group bna hai
        // un sab ka total quality sum kitna hai (pause le lo ynha aur again read kro)

        // achcha ek unitary method ka basic concept samjho
        // agr 1 unit quality ka wage = 1.2
        // to 10 unit quality ka wage = 12 shi n (1.2*10)
        // yani simple formula me dekhe to (quality * (wage/quality))
        // done samjh aaya

        // ek baat aur boluga, ab ek baar page ko dekho, jo bhi k worker
        // honge unka wage/quality ka ratio same hona chaiye, thik..
        // yani suppose hmare pass pair hai
        //  => {1.2,10} , {1.3,10} , {1.5,10} K=2 hai
        // then what if mai pair 1,2 choose kru
        // to mujhe dono worker ko kitna wage dena padega
        // dono ki mila ki quality = 20 hai
        // es formule ke according (quality * (wage/quality))
        // (wage/quality ka ration kya honachaiye ? ? ? )
        // 1.2 ya 1.3
        // ab ek baar top wali photo dekho
        // I guess sab ratio same hona chaiye to 1.3 ham choose krenge
        // yahi crutial point hai

        // kyu 1.3 abhi bhai ? aakhir kyu ?>> 

        // dekho ek keh rha w/q = 1.2
        // ek kle rha w/q=1.3
        // to first example yaad kro
        // yani test case ek 
        // quality = [10,20,5], wage = [70,50,30], k = 2
        // agr zeroth wale ko 70 wage mila yani 1 unit ke liye 7
        // to second wale ko (consider 0th indexing) jo hi 10 ka half tha
        // to quality 70/2 hui -> 35 wage milega thik n

        // basically mai yue kehna chah rha ki jo bhi K group of worker me 
        // wage/quality ka ratio same hoga, usse hi es formule me multiply kroge kyuki
        //(quality * (wage/quality)) kyuki puchchale ratio apne wage minimum se zyada leke , es ratio ko balanace krke us K group ke maximum wage/quality ke barabar karenge


        // use copy pen and only try second test case of problme samjh jaoge ye line

        // nhi to milte hai comment section hai .😊😊😊😊
        // milke aur achche se decode krenge.
        for(int i=0;i<n;i++){

            // quality ka sum nikal
            currentQuality += wqRatio[i].second;
            pq.push(wqRatio[i].second);

            // agr k se zyada worker ho gye
            if(pq.size()>k){
                // uski quality minus kro jo max hai

                // abhi bhai ek doubt, tum K worker se zyada hone pe
                // maixum quantity ke worker ko kyu remove kr rhe ho

                // Let's again see our euqation
                // (quality * (wage/quality))
                // wage/ quality ham change nhi kar sakte majboori hai

                // ham bas K worker ko choose krte time quality minimum rakhne ki kosis krunga


                // kya abhi bhai  (wage/quality) kyu nhi maintain kar skte
                // ekho hamne  (wage/quality) ratio se sort kiya hai
                // to agr mai ith ind me hu, to ith ind ke baad ya to
                //  (wage/quality) ka ration same hoga ya phir badhega 

                //  (wage/quality) mere control me nhi hai
                // ab socho ek quantity mere control me nhi hia
                // ab agr ma K se zyada worker ho rhe hai to ek 
                // use drop krunga jo quality zyada bnaye huye hai

                // formula 
                // amount =>  quality*(wage/quality)
                // amount aur quality directly proportional hai 
                // esiliye hamen priority queue use kiya
                // taki k se zyada worker hone pe jo maximum quality wala worker hoga pop kr dunga

                // top minus kr diya
                currentQuality-=pq.top();
                // pop kar do
                pq.pop();
            }

            // agr K worker hai to 
            if(pq.size()==k){

                // simple vhi formula rkha (quality * (wage/quality))
                // ynha pe ith ind ka ki wage/quality kyu liya
                // kyuki ith ind pe hi group complete kyu K worker ka
                // aur data sorted ahi to wage/quality ka ratio
                // ith ind wale ka hi sabse zyada hoga k group me 
                

                // ton baki ki jo bhi K worker ke ratio honge, vo aona wage 
                // bda ke,  (wage/quality) equal krenge heighest ke 


                // if you have doubt, dont worry brother, feel free to ask in commnet section 😊
                ans=min(ans,currentQuality*wqRatio[i].first);
            }
        }

        // return answer 
        return ans;
    }
};