class Solution {
public:
    int myAtoi(string s) {
      string st="";
      int i=0;
      while(s[i]==' ' && st.size()==0 && i<s.size())
      {
          ++i;
      }
      while(s[i]=='0' && st.size()==0 && i<s.size())
      {
          if(s[i+1]=='+' || s[i+1]=='-')
          {
              return 0;
          }
          ++i;
      }
      while((s[i]=='+'||s[i]=='-') && st.size()==0 && i<s.size())
      {
          st.push_back(s[i]);
          ++i;
      }
      while(s[i]>='0' && s[i]<='9')
      {
          st.push_back(s[i]);
          ++i;
      }
        cout<<st<<endl;
      long long value=0;
        int flag=0;
      if(st[0]=='-')
      {
          flag=1;
      }
      else if(st[0]>='0' && st[0]<='9')
      {
          value=value*10+(st[0]-'0');
      }
      for(int i=1;i<st.size();++i)
      {
          if(value>INT_MIN &&value<INT_MAX)
              value=value*10+(st[i]-'0');
          else if(value<=INT_MIN)
          {
              return INT_MIN;
          }
          else
          {
              if(flag==0)
                  return INT_MAX;
              else
                  return INT_MIN;
          }
      }
      if(flag==1)
      {
          value=-value;
      }
      if(value>=INT_MAX)
      {
          return INT_MAX;
      }
    if(value<=INT_MIN)
    {
            return INT_MIN;
    }
        return value;
    }
        
};