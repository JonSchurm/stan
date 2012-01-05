// Code generated by Stan version alpha.0

#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <boost/exception/all.hpp>
#include <Eigen/Dense>
#include <stan/agrad/agrad.hpp>
#include <stan/agrad/special_functions.hpp>
#include <stan/agrad/matrix.hpp>
#include <stan/gm/command.hpp>
#include <stan/io/cmd_line.hpp>
#include <stan/io/dump.hpp>
#include <stan/io/reader.hpp>
#include <stan/io/writer.hpp>
#include <stan/io/csv_writer.hpp>
#include <stan/maths/matrix.hpp>
#include <stan/maths/special_functions.hpp>
#include <stan/mcmc/hmc.hpp>
#include <stan/mcmc/sampler.hpp>
#include <stan/mcmc/prob_grad_ad.hpp>
#include <stan/prob/distributions.hpp>

namespace test_model_namespace {

using std::vector;
using std::string;
using std::stringstream;
using stan::agrad::var;
using stan::mcmc::prob_grad_ad;
using stan::io::dump;
using std::istream;
using namespace stan::maths;
using namespace stan::prob;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;
typedef Eigen::Matrix<stan::agrad::var,Eigen::Dynamic,1> vector_v;
typedef Eigen::Matrix<stan::agrad::var,1,Eigen::Dynamic> row_vector_v;
typedef Eigen::Matrix<stan::agrad::var,Eigen::Dynamic,Eigen::Dynamic> matrix_v;

class test_model : public prob_grad_ad {
private:
public:
    test_model(stan::io::var_context& context__)
        : prob_grad_ad::prob_grad_ad(0) {
        unsigned int pos__;
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;


        set_param_ranges();
    } // dump ctor

    void set_param_ranges() {
        num_params_r__ = 0U;
        param_ranges_i__.clear();
        ++num_params_r__;
    }

    void transform_inits(const stan::io::var_context& var_context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__) {
        params_r__.clear();
        params_i__.clear();
        stan::io::writer<double> writer__(params_r__,params_i__);
        unsigned int pos__;
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;


        if (!(var_context__.contains_r("y")))
            throw std::runtime_error("variable y missing");
        if (var_context__.dims_r("y").size() != 0)
            throw std::runtime_error("require 0 dimensions for variable y");
        vals_r__ = var_context__.vals_r("y");
        pos__ = 0U;
        double y(0);
        y = vals_r__[pos__++];
        writer__.scalar_lub_unconstrain(-(1),1,y);
    }

    var log_prob(vector<var>& params_r__,
                 vector<int>& params_i__) {

        var lp__(0.0);
        // model parameters
        stan::io::reader<var> in__(params_r__,params_i__);

        var y = in__.scalar_lub_constrain(-(1),1,lp__);

        // derived variables


        // model body
        lp__ = (lp__ + log(fmax(0,(1 - fabs(y)))));

        return lp__;

    } // log_prob()

    void write_csv(std::vector<double>& params_r__,
                   std::vector<int>& params_i__,
                   std::ostream& o__) {
        stan::io::reader<double> in__(params_r__,params_i__);
        stan::io::csv_writer writer__(o__);
        // read-transform, write parameters
        double y = in__.scalar_lub_constrain(-(1),1);
        writer__.write(y);

        // write transformed parameters



        // write generated quantities


        writer__.newline();
    }

}; // model

} // namespace

int main(int argc, const char* argv[]) {
    try {
        stan::gm::nuts_command<test_model_namespace::test_model>(argc,argv);
    } catch (std::exception& e) {
        std::cerr << std::endl << "Exception: " << e.what() << std::endl;
        std::cerr << "Diagnostic information: " << std::endl << boost::diagnostic_information(e) << std::endl;
    }
}

