import com.aliyun.odps.udf.UDF;
import com.hankcs.hanlp.HanLP;
import com.hankcs.hanlp.seg.Segment;
import com.hankcs.hanlp.seg.common.Term;

import java.util.List;
import java.util.regex.Pattern;


public class getPlaceName extends UDF {
    public String evaluate (String inputStr){
        if(inputStr == null) return null;
        String result = null;

        Segment segment = HanLP.newSegment().enablePlaceRecognize(true);
        List<Term> termList = segment.seg(inputStr.toString());
        StringBuilder places = new StringBuilder();
        for(Term t: termList){
            String s = t.toString();
            if(Pattern.matches(".*/ns$",s)){
                places.append(s.replace("/ns",""));
                places.append(" ");
            }
        }
        result = places.toString();
        return result;
    }
}

